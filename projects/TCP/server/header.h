#ifndef MY_HEADER_H
#define MY_HEADER_H

#include "../shared/helpers.h"

struct tcphdr * listen_syn_package(uint16_t * buffer, size_t buffer_size);
void send_ack_packet(struct sockaddr_in source, struct sockaddr_in destination,
                     struct tcphdr *header, uint32_t ack_num);

#endif