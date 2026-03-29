#ifndef MY_HEADER_H
#define MY_HEADER_H

#include "helpers/helpers.h"

void send_sync_packet(struct tcphdr *header, unsigned int src_port,
                                             unsigned int dest_port,
                                             const uint32_t destination_ipv4);

#endif
