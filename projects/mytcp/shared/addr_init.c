#include "helpers.h"

/* This function will initialize a socket addr struct of AF_INET family*/
struct sockaddr_in addr_init(const unsigned int *port,const  uint32_t  *ipv4_addr){
    struct sockaddr_in dest;
    dest.sin_family = AF_INET;     // Set the address family to IPv4
    dest.sin_port = *port; // right endien
    dest.sin_addr.s_addr = *ipv4_addr;

    return dest;
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