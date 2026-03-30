#ifndef CLIENT_H
#define CLIENT_H

#include "../shared/helpers.h"

void send_sync_packet(struct sockaddr_in source, struct sockaddr_in destination,
                                                 struct tcphdr *header);
void send_syn_ack_pack(struct sockaddr_in source, struct sockaddr_in destination,
                                                struct tcphdr *client_header,
                                                struct tcphdr *server_header);
void *client_thread(void *arg);
#endif
