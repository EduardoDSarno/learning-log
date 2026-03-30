#ifndef SERVER_H
#define SERVER_H

#include "../shared/helpers.h"

struct tcphdr * listen_syn_package(uint16_t dest_port);
void listen_ack_package(uint16_t dest_port);
void send_ack_packet(struct sockaddr_in source, struct sockaddr_in destination,
                     struct tcphdr *client_header, struct tcphdr *server_header);

void *server_thread(void *arg);

#endif