#include "helpers.h"

/* This function will initialize a socket addr struct of AF_INET family*/
struct sockaddr_in addr_init(const unsigned int *port,const  uint32_t  *ipv4_addr){
    struct sockaddr_in dest;
    dest.sin_family = AF_INET;     // Set the address family to IPv4
    dest.sin_port = *port; // right endien
    dest.sin_addr.s_addr = *ipv4_addr;

    return dest;
}