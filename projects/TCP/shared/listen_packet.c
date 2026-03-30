#include "helpers.h"
#include <stdio.h>
#include <pcap/pcap.h>

/*
 * WHY PCAP INSTEAD OF RAW SOCKETS:
 *   On macOS, socket(PF_INET, SOCK_RAW, IPPROTO_TCP) does NOT receive
 *   packets that travel over lo0 (loopback). macOS routes all same-host
 *   traffic through lo0 regardless of IP (even 192.168.x.x to itself),
 *   and raw sockets sit above the layer where lo0 copies are delivered.
 *
 *   libpcap (what Wireshark uses) hooks in via BPF, which operates below
 *   that layer and CAN receive lo0 packets. macOS ships with libpcap.
 *
 * BUG FIXES vs original raw-socket version:
 *   1. Flag check: was !(flags & expected) — exits on ANY bit matching.
 *      A plain SYN satisfied TH_SYN|TH_ACK. Fixed to require ALL bits.
 *   2. Port filtering: skip packets not destined for our port.
 *   3. Memory bug: returned pointer into middle of malloc'd buffer. Fixed
 *      by copying TCP header into a fresh malloc before returning.
 */

/* lo0 is where macOS sends all same-host traffic, DLT_NULL = 4-byte prefix */
#define CAPTURE_IFACE "lo0"
#define DLT_NULL_HDR_LEN 4
#define PCAP_TIMEOUT_MS  200

struct tcphdr *listen_packet(uint8_t expected_flags, uint16_t dest_port)
{
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t *handle = pcap_open_live(CAPTURE_IFACE, 65535, 1,
                                    PCAP_TIMEOUT_MS, errbuf);
    if (!handle) {
        fprintf(stderr, "[listen] pcap_open_live(%s): %s\n",
                CAPTURE_IFACE, errbuf);
        return NULL;
    }

    /* BPF filter narrows captures to TCP on our destination port */
    char filter_expr[64];
    if (dest_port != 0)
        snprintf(filter_expr, sizeof(filter_expr), "tcp dst port %u", dest_port);
    else
        snprintf(filter_expr, sizeof(filter_expr), "tcp");

    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter_expr, 0, PCAP_NETMASK_UNKNOWN) == -1 ||
        pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "[listen] pcap filter error: %s\n", pcap_geterr(handle));
        pcap_freecode(&fp);
        pcap_close(handle);
        return NULL;
    }
    pcap_freecode(&fp);

    int dlt = pcap_datalink(handle);
    printf("[listen] pcap open on %s (dlt=%d), waiting for "
           "flags=0x%02x dest_port=%u\n",
           CAPTURE_IFACE, dlt, expected_flags, dest_port);

    size_t tries = 0;
    while (tries <= MAX_CONNECT_TRIES) {
        struct pcap_pkthdr *pkthdr;
        const uint8_t *pkt;
        int ret = pcap_next_ex(handle, &pkthdr, &pkt);
        if (ret == 0) continue;   /* timeout — try again */
        if (ret < 0) {
            fprintf(stderr, "[listen] pcap_next_ex: %s\n", pcap_geterr(handle));
            break;
        }

        /* Skip the data-link header to reach the IP header */
        size_t dl_offset = 0;
        if (dlt == DLT_NULL || dlt == DLT_LOOP)
            dl_offset = DLT_NULL_HDR_LEN;
        else if (dlt == DLT_EN10MB)
            dl_offset = 14;

        if (pkthdr->caplen < dl_offset + sizeof(struct ip)) {
            tries++;
            continue;
        }

        struct ip *ip_hdr = (struct ip *)(pkt + dl_offset);
        size_t ip_len = ip_hdr->ip_hl * 4;

        if (pkthdr->caplen < dl_offset + ip_len + sizeof(struct tcphdr)) {
            tries++;
            continue;
        }

        struct tcphdr *tcp_hdr =
            (struct tcphdr *)(pkt + dl_offset + ip_len);

        printf("[listen] candidate: sport=%u dport=%u flags=0x%02x "
               "(want all of 0x%02x)\n",
               ntohs(tcp_hdr->th_sport), ntohs(tcp_hdr->th_dport),
               tcp_hdr->th_flags, expected_flags);

        /* BUG FIX 1: require ALL expected flag bits to be set */
        if ((tcp_hdr->th_flags & expected_flags) == expected_flags) {
            printf("[listen] matched!\n");

            /* BUG FIX 3: fresh allocation so caller can free() it */
            struct tcphdr *result = malloc(sizeof(struct tcphdr));
            if (!result) {
                pcap_close(handle);
                return NULL;
            }
            memcpy(result, tcp_hdr, sizeof(struct tcphdr));
            pcap_close(handle);
            return result;
        }

        tries++;
    }

    fprintf(stderr, "[listen] no matching packet after %zu tries\n", tries);
    pcap_close(handle);
    return NULL;
}
