// gcc main.c -o main && sudo ./main

#include "header.h"
#include "helpers/helpers.h"
#include <stdlib.h>
#include <string.h>

int main(void){

    unsigned int src_port = 12345;
    unsigned int dest_port = 80;
    uint32_t destination_ipv4 = inet_addr("127.0.0.1");
    uint32_t source_ipv4 = inet_addr("127.0.0.1");
    uint8_t *message = NULL;


    struct tcphdr *header = malloc(sizeof(struct tcphdr));
    header->th_dport = htons(dest_port);
    header->th_sport = htons(src_port);
    header->th_off   = sizeof(struct tcphdr) / 4; // 32 bit word (unix def )

    
    // getting formmated data on buffer
    size_t size = 0;
    uint16_t * buffer = format_check_sum(header, message, 0, source_ipv4,destination_ipv4, &size);

    // check summing
    uint16_t checksum = check_sum(buffer, &size);

    header->th_sum = checksum;

    send_sync_packet(header, src_port, dest_port, destination_ipv4);

    free(buffer);
    free(header);

}