#include "socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* This function will initiate a socket by recving a port and address (Ipv4)
    It will return NULL if has problem with memory allocation OR creating a 
    file descriptor index
    */
Socket *socket_init(const uint16_t port,const uint32_t ipv4)
{
    Socket * new_socket = malloc(sizeof(Socket));
    if (new_socket == NULL) {
        fprintf(stderr, "Error Creating new Socket");
        goto cleanup;
    }

    new_socket->port = port;
    new_socket->ipv4 = ipv4;

    int file_d = socket(AF_INET, SOCK_STREAM, 0);

    if (file_d < 0) {
        perror("Socket failled");
        goto cleanup;
    }
    new_socket->file_descriptor_index = file_d;

    return new_socket;

    cleanup:
        if (new_socket != NULL) free(new_socket);
        return NULL;
}