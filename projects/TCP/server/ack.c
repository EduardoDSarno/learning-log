#include "header.h"
#include <stddef.h>
#include <stdlib.h>

/*This function will receive a buffer that will be filled with the data received from 
  the trasmission and it will cast it and return a tcpheader of it*, caller needs malloc*/
struct tcphdr * listen_syn_package(uint16_t * buffer, size_t buffer_size){

    // raw socket
    int sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);

    struct sockaddr_in src = addr_init(NULL, NULL);
    socklen_t src_len = sizeof(src);

    /* we use pointer because recvfrom writes back to the struct*/
    size_t size = recvfrom(sockfd, buffer, buffer_size, 0, (struct sockaddr *)&src, &src_len);

    /*Casting the buffer into the received header*/
    struct tcphdr *received_header = (struct tcphdr *)buffer;

    return received_header;
}

void send_ack_packet(struct sockaddr_in source, struct sockaddr_in destination,
                     struct tcphdr *header, uint32_t ack_num)
{
    send_packet(source, destination, header, TH_ACK, ack_num);
}
