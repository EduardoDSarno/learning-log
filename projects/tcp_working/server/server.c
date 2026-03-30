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

/* Wrapper will return the header stuct */
struct tcphdr * listen_syn_package(uint16_t dest_port){
    return listen_packet(TH_SYN, dest_port);
}

/* This case we will just be printing connected, in reality we would start exahcnge data
   I might implement this later*/
void listen_ack_package(uint16_t dest_port){
    struct tcphdr *p = listen_packet(TH_ACK, dest_port);
    if (p) { free(p); }
    printf("CONNECTED\n");
}

/* server thread steps 2 and 4*/
void *server_thread(void *arg){
    const ConnectionData *data = (const ConnectionData *)arg;

    // server listens on destination port (port 80 in this setup)
    uint16_t my_port = data->destination.sin_port; /* stored host byte order */
    printf("[server] starting, my port = %u\n", my_port);

    // it is going to wait for a syn
    struct tcphdr *received_syn = listen_syn_package(my_port);
    // then will create it's header
    struct tcphdr *server_header = malloc(sizeof(struct tcphdr));
    if(server_header == NULL){
        fprintf(stderr, "memory allocation error");
        return NULL;
    }
    // send the packet with the header
    send_ack_packet(data->source, data->destination, received_syn, server_header);
    // pt4 Server listens for ACK and print if success
    listen_ack_package(my_port);

    free(server_header);
    free(received_syn);
    return NULL;
}
