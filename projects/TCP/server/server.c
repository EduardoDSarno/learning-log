#include "server.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


void send_ack_packet(struct sockaddr_in source, struct sockaddr_in destination,
                     struct tcphdr *client_header, struct tcphdr *server_header)
{

    uint32_t ack_num = ntohl(client_header->th_seq) + 1;

    uint32_t seq_number = htonl(rand());
    server_header->th_seq = seq_number;

    /*For the flags heere since each flag is in one opsiton (0-7) as bits in the byte
      when we or them is the same as adding them toghter to the flag from SYN because SYN-ACK*/
    send_packet(source, destination, server_header, (TH_SYN | TH_ACK), ack_num);
}

/*This funciton will listen to packages from SYN it will create a buffer called recvfrom
  put the result on the buffer and the return the value of the buffer casted to the structure
  of the tcp header, caller must free*/
struct tcphdr * listen_syn_package(){
    return listen_packet(TH_SYN);
}

void listen_ack_package(){
    listen_packet(TH_ACK);
    printf("CONNECTED");
}
