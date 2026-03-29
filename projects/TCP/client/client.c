#include "client.h"
#include <stdlib.h>

void send_sync_packet(struct sockaddr_in source, struct sockaddr_in destination,
                                                 struct tcphdr *header)
{
    uint32_t seq_number  = htonl(rand());
    header->th_seq = seq_number;

    send_packet(source, destination, header, TH_SYN, 0);
}
