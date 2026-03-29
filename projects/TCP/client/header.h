#ifndef MY_HEADER_H
#define MY_HEADER_H

#include "../shared/helpers.h"

void send_sync_packet(struct sockaddr_in source, struct sockaddr_in destination,
                                                 struct tcphdr *header);

#endif
