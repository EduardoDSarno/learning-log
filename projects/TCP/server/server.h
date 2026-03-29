#ifndef SERVER_H
#define SERVER_H

#include "../shared/helpers.h"

struct tcphdr * listen_syn_package();
void listen_ack_package();
void send_ack_packet(struct sockaddr_in source, struct sockaddr_in destination,
                     struct tcphdr *client_header, struct tcphdr *server_header);

#endif