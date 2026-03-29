#include "header.h"

void send_sync_packet(struct sockaddr_in source, struct sockaddr_in destination,
                                                 struct tcphdr *header)
{
    send_packet(source, destination, header, TH_SYN, 0);
}
