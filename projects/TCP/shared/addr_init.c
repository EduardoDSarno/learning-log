#include "helpers.h"
#include <ifaddrs.h>
#include <net/if.h>

/* This function will initialize a socket addr struct of AF_INET family*/
struct sockaddr_in addr_init(const unsigned int *port,const  uint32_t  *ipv4_addr){
    struct sockaddr_in dest;
    dest.sin_family = AF_INET;     // Set the address family to IPv4
    dest.sin_port = *port; // right endien
    dest.sin_addr.s_addr = *ipv4_addr;

    return dest;
}

/*
 * Returns the IPv4 address of the first non-loopback interface (network byte order).
 * On macOS, SOCK_RAW IPPROTO_TCP sockets do NOT receive packets sent over lo0 (127.0.0.1).
 * The kernel handles loopback at a layer below where raw sockets get copies, so recvfrom
 * blocks forever. Using a real interface IP (en0, en1, etc.) routes through the normal
 * IP stack where raw sockets do receive copies.
 */
uint32_t get_local_ip(void)
{
    struct ifaddrs *ifap;
    if (getifaddrs(&ifap) != 0) {
        perror("getifaddrs");
        return inet_addr("127.0.0.1");
    }

    for (struct ifaddrs *ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) continue;
        if (ifa->ifa_addr->sa_family != AF_INET) continue;
        if (ifa->ifa_flags & IFF_LOOPBACK) continue;
        if (!(ifa->ifa_flags & IFF_UP)) continue;

        uint32_t ip = ((struct sockaddr_in *)ifa->ifa_addr)->sin_addr.s_addr;
        char ip_str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &ip, ip_str, sizeof(ip_str));
        printf("[init] using interface %s  ip=%s\n", ifa->ifa_name, ip_str);
        freeifaddrs(ifap);
        return ip;
    }

    freeifaddrs(ifap);
    fprintf(stderr, "[init] no non-loopback interface found, falling back to 127.0.0.1\n");
    return inet_addr("127.0.0.1");
}

/* Initializes a ConnectionData struct with addresses and an empty header, caller must free */
ConnectionData *connection_init(unsigned int src_port, uint32_t src_ipv4,
                                unsigned int dest_port, uint32_t dest_ipv4)
{
    ConnectionData *conn = malloc(sizeof(ConnectionData));
    if (conn == NULL) {
        fprintf(stderr, "Error allocating ConnectionData");
        return NULL;
    }

    conn->source      = addr_init(&src_port, &src_ipv4);
    conn->destination  = addr_init(&dest_port, &dest_ipv4);

    return conn;
}