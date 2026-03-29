#include "server.h"
#include <stddef.h>
#include <stdlib.h>

/*This function will receive a buffer that will be filled with the data received from 
  the trasmission and it will cast it and return a tcpheader of it*, caller needs malloc*/
struct tcphdr * listen_syn_package(uint16_t * buffer, size_t buffer_size){

    // raw socket
    int sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);

    struct sockaddr_in src = {0};
    socklen_t src_len = sizeof(src);

    /* we use pointer because recvfrom writes back to the struct*/
    size_t size = recvfrom(sockfd, buffer, buffer_size, 0, (struct sockaddr *)&src, &src_len);

    /*Casting the buffer into the received header*/
    struct tcphdr *received_header = (struct tcphdr *)buffer;

    return received_header;
}

void send_ack_packet(struct sockaddr_in source, struct sockaddr_in destination,
                     struct tcphdr *client_header, struct tcphdr *server_header)
{

    uint32_t ack_num = ntohl(client_header->th_seq) + 1;
    uint32_t seq_number = htonl(rand());
    server_header->th_seq = seq_number;

    send_packet(source, destination, server_header, (TH_SYN | TH_ACK), ack_num);
}
