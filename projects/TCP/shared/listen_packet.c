#include "helpers.h"

/*This function will listen for packages, create a buffer with recvfrom,
  cast it to a tcp header and verify the expected flag, caller must free*/
struct tcphdr * listen_packet(uint8_t expected_flags){

    // raw socket
    int sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);

    uint8_t *buffer = malloc(MAX_BUFFER_SIZE); // max packet size
    struct sockaddr_in src = {0};
    socklen_t src_len = sizeof(src);
    
    /*Casting the buffer into the received header*/
    struct tcphdr *received_header = (struct tcphdr *)buffer;
    recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&src, &src_len);

    // On mac the OS gives you the full TCP pakcat containing IP header as well
    // so we cast the buffer into the ipheader and we put the received header
    // to go to the buffer jumping the ip header bytes (4 = 32 bit words)
    struct ip *ip_header = (struct ip *)buffer;
    received_header = (struct tcphdr *)(buffer + (ip_header->ip_hl * 4));

    /* we use pointer because recvfrom writes back to the struct*/
    while (!(received_header->th_flags & expected_flags)) 
    {
      recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&src, &src_len);

      struct ip *ip_header = (struct ip *)buffer;
      received_header = (struct tcphdr *)(buffer + (ip_header->ip_hl * 4));
    }

    return received_header;
}
