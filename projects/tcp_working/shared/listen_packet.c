#include "helpers.h"
#include <stdio.h>
#include <unistd.h>

/*
 * BUG FIXES vs original:
 *   1. Flag check: was !(flags & expected) which exits on ANY matching bit.
 *      Fixed to (flags & expected) == expected so ALL bits must be set.
 *      Old code: client waiting for TH_SYN|TH_ACK would accept a plain SYN.
 *
 *   2. Port filtering: raw socket sees ALL TCP traffic on the system.
 *      Added dest_port param so we skip packets not destined for our port.
 *      Without this the 100-try limit can exhaust on background traffic.
 *
 *   3. Memory bug: original returned received_header which pointed into the
 *      middle of buffer (buffer + ip_hl*4). Callers then free() that pointer
 *      which is not the start of the malloc'd block = undefined behavior.
 *      Fixed: copy TCP header into a fresh malloc, free the buffer, return copy.
 *
 *   4. Socket leak: close(sockfd) on all exit paths.
 */
struct tcphdr *listen_packet(uint8_t expected_flags, uint16_t dest_port)
{
    int sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("[listen] socket");
        return NULL;
    }

    uint8_t *buffer = malloc(MAX_BUFFER_SIZE);
    if (!buffer) {
        fprintf(stderr, "[listen] malloc failed\n");
        close(sockfd);
        return NULL;
    }

    struct sockaddr_in src = {0};
    socklen_t src_len = sizeof(src);
    size_t tries = 0;

    printf("[listen] waiting for flags=0x%02x on dest_port=%u\n",
           expected_flags, dest_port);

    while (tries <= MAX_CONNECT_TRIES) {
        ssize_t n = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0,
                             (struct sockaddr *)&src, &src_len);
        if (n < 0) {
            perror("[listen] recvfrom");
            break;
        }

        struct ip *ip_hdr = (struct ip *)buffer;
        size_t ip_hdr_len = ip_hdr->ip_hl * 4;

        /* drop packets too short to hold a TCP header */
        if ((size_t)n < ip_hdr_len + sizeof(struct tcphdr)) {
            tries++;
            continue;
        }

        struct tcphdr *tcp_hdr = (struct tcphdr *)(buffer + ip_hdr_len);

        /* BUG FIX 2: skip packets not destined for our port */
        if (dest_port != 0 && ntohs(tcp_hdr->th_dport) != dest_port) {
            printf("[listen] skip (wrong port): dport=%u flags=0x%02x\n",
                   ntohs(tcp_hdr->th_dport), tcp_hdr->th_flags);
            tries++;
            continue;
        }

        printf("[listen] candidate: sport=%u dport=%u flags=0x%02x (want 0x%02x)\n",
               ntohs(tcp_hdr->th_sport), ntohs(tcp_hdr->th_dport),
               tcp_hdr->th_flags, expected_flags);

        /* BUG FIX 1: require ALL expected flag bits to be set */
        if ((tcp_hdr->th_flags & expected_flags) == expected_flags) {
            printf("[listen] matched! returning packet\n");

            /* BUG FIX 3: copy to a fresh allocation so caller can free() it */
            struct tcphdr *result = malloc(sizeof(struct tcphdr));
            if (!result) {
                fprintf(stderr, "[listen] malloc result failed\n");
                free(buffer);
                close(sockfd);
                return NULL;
            }
            memcpy(result, tcp_hdr, sizeof(struct tcphdr));
            free(buffer);
            close(sockfd); /* BUG FIX 4 */
            return result;
        }

        tries++;
    }

    fprintf(stderr, "[listen] no matching packet after %zu tries\n", tries);
    free(buffer);
    close(sockfd); /* BUG FIX 4 */
    return NULL;
}
