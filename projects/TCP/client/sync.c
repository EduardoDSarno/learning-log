#include "header.h"

void send_sync_packet(struct tcphdr *header, unsigned int src_port,
                                             unsigned int *dest_port,
                                             const uint32_t *destination_ipv4){


    int sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);

    struct sockaddr_in dest =  addr_init(dest_port, destination_ipv4);
    socklen_t dest_len = sizeof(dest);
    header->th_flags = TH_SYN;

   size_t bytes_send = sendto(sockfd,header, sizeof(struct tcphdr), 0, (struct sockaddr *)&dest, dest_len);

   if (bytes_send == -1) {
    perror("sendto failed");
}

   printf("%lu", bytes_send);

}
