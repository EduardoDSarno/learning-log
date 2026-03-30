#include "helpers.h"
#include <unistd.h>

/*This isa  generic send packet funciton used by both sync and ack (they will have wrappers for clarity)
    the only modification between them is hte flag and ack_num*/
void send_packet(struct sockaddr_in source, struct sockaddr_in destination,
                 struct tcphdr *header, uint8_t flags, uint32_t ack_num)
{

    int sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) { perror("send_packet socket"); return; }

    socklen_t dest_len = sizeof(destination);
    header->th_flags = flags;
    header->th_ack   = htonl(ack_num);
    header->th_dport = htons(destination.sin_port); 
    header->th_sport = htons(source.sin_port);
    header->th_off   = sizeof(struct tcphdr) / 4; // 32 bit word (uni
    
    // getting formmated data on buffer
    size_t size = 0;
    uint16_t * buffer = format_check_sum(header, NULL, 0, source.sin_addr.s_addr, destination.sin_addr.s_addr, &size);


    // check summing
    /*I found out that OS does the verification for the check sum automatically
        but I will probably do my own after setting everything up*/
    uint16_t checksum = check_sum(buffer, &size);

    header->th_sum = checksum;
    int bytes_send = sendto(sockfd, header, sizeof(struct tcphdr), 0, (struct sockaddr *)&destination, dest_len);

    if (bytes_send == -1) {
        perror("sendto failed");
    } else {
        printf("[send] sent %d bytes: sport=%u dport=%u flags=0x%02x\n",
               bytes_send,
               ntohs(header->th_sport), ntohs(header->th_dport),
               header->th_flags);
    }

    free(buffer);
    close(sockfd); /* BUG FIX 4: was leaking fd */
}
