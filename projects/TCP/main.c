// gcc main.c -o main && sudo ./main

#include "client/client.h"
#include "shared/helpers.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    srand(time(NULL)); // for rand sequence number
    unsigned int src_port = 12345;
    unsigned int dest_port = 80;
    uint32_t destination_ipv4 = inet_addr("127.0.0.1");
    uint32_t source_ipv4 = inet_addr("127.0.0.1");

    struct sockaddr_in source = addr_init(&src_port, &source_ipv4);
    struct sockaddr_in destination = addr_init(&dest_port, &destination_ipv4);

    struct tcphdr *header = malloc(sizeof(struct tcphdr));

    send_sync_packet(source, destination, header);

    free(header);

}