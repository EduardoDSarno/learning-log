#include "client.h"
#include <stdint.h>


/*This function receives a address and port and return a pointer
    to a TCP client*/
TCPClient *client_init(const uint16_t client_port, const uint32_t client_ipv4){

    // initialize to NULL for not freeing unitialized
    TCPClient *client =  NULL;
    Socket *client_socket = NULL;

    client = safe_malloc(sizeof(TCPClient));
    if (is_null(client, "error on client init")) goto cleanup;

    client_socket = socket_init(client_port, client_ipv4);
    if (is_null(client_socket, "error on socket client init")) goto cleanup;

    client->client_socket = *client_socket;
    client->state = NOT_CONNECTED;

    safe_free(client_socket, sizeof(Socket));
    return client;

    cleanup:
        safe_free(client, sizeof(TCPClient));
        safe_free(client_socket, sizeof(Socket));
        return NULL;
}

/* This function will connect the client to a Server
    it will return  -1 if fails or 0 for success*/
int client_connect( TCPClient * client, const uint16_t server_port, const uint32_t server_ipv4)
{
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);

    server_addr.sin_addr.s_addr = server_ipv4;
    server_addr.sin_port        = htons(server_port);
    server_addr.sin_family      = AF_INET;

    int result = connect(client->client_socket.file_descriptor_index, (struct sockaddr *)&server_addr, addr_len);

    if (result < 0) {
        perror("Connection attempt failed");
        return result;
    }


    client->server_ipv4 = server_ipv4;
    client->server_port = server_port;

    client->state = CONNECTED;
    return result;

}