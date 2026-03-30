#include "client.h"
#include <stdio.h>
#include <stdlib.h>

void send_sync_packet(struct sockaddr_in source, struct sockaddr_in destination,
                                                 struct tcphdr *header)
{
    uint32_t seq_number  = htonl(rand());
    header->th_seq = seq_number;

    send_packet(source, destination, header, TH_SYN, 0);
}

void send_syn_ack_pack(struct sockaddr_in source, struct sockaddr_in destination,
                                                struct tcphdr *client_header,
                                                struct tcphdr *server_header)
{

    // all of these conversions are becasue I am in a MAC that uses little endian, 
    // so I need to convert it (since the netwrok uses big endian) and do the math
    // and then convert it back
    uint32_t seq = ntohl(client_header->th_seq) + 1;
    client_header->th_seq = htonl(seq);

    uint32_t ack = ntohl(server_header->th_seq) + 1;

    send_packet(source, destination, client_header, TH_ACK, ack);

}
/* Client thread steps 1 and 3*/
void *client_thread(void *arg){
    const ConnectionData *data = (const ConnectionData *)arg;

    // client listens on source port (port 12345 in this setup)
    uint16_t my_port = data->source.sin_port; /* stored host byte order */
    printf("[client] starting, my port = %u\n", my_port);

    struct tcphdr *client_header = malloc(sizeof(struct tcphdr));
    if(client_header == NULL){
        fprintf(stderr, "memory allocation error");
        return NULL;
    }
    // 1: send first SYN
    send_sync_packet(data->source, data->destination, client_header);

    // pt3 Client listens for SYN-ACK destined to our port, then send final ACK
    struct tcphdr *received_syn_ack = listen_packet(TH_SYN | TH_ACK, my_port);
    send_syn_ack_pack(data->source, data->destination, client_header, received_syn_ack);

    free(client_header);
    free(received_syn_ack);
    return NULL;
}