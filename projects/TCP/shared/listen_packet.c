#include "helpers.h"

/*This function will listen for packages, create a buffer with recvfrom,
  cast it to a tcp header and verify the expected flag, caller must free*/
struct tcphdr * listen_packet(uint8_t expected_flags){

    // raw socket
    int sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);

    uint8_t *buffer = malloc(MAX_BUFFER_SIZE); // max packet size
    struct sockaddr_in src = {0};
    socklen_t src_len = sizeof(src);

    /* we use pointer because recvfrom writes back to the struct*/
    recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&src, &src_len);

    /*Casting the buffer into the received header*/
    struct tcphdr *received_header = (struct tcphdr *)buffer;

    if (!(received_header->th_flags & expected_flags)){
        perror("unexpected flag");
        return NULL;
    }
    return received_header;
}
