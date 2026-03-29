#ifndef HELPERS_H
#define HELPERS_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include "pseIPHeader.h"

uint16_t* format_check_sum(struct tcphdr *header, const uint8_t *message_buffer, size_t buffer_size,
        const uint32_t ipv4_scr,
        const uint32_t ipv4_dest,
        size_t *out_size_buffer);

uint16_t check_sum(uint16_t *buffer, size_t *size);
struct sockaddr_in addr_init(const unsigned int *port,const uint32_t *ipv4_addr);
void send_packet(struct sockaddr_in source, struct sockaddr_in destination,
                 struct tcphdr *header, uint8_t flags, uint32_t ack_num);

#endif
