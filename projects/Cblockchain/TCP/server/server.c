#include "server.h"
#include "../../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>



TCPServer *server_init(const uint16_t port,const uint32_t ipv4)
{
    TCPServer *server = safe_malloc(sizeof(TCPServer));

    Socket *server_socket;

    server_socket = socket_init(port, ipv4);

    if (server_socket == NULL) {
        fprintf(stderr, "Error Creating server Sockert");
        goto cleanup;
    }


    // free(server_socket)
    cleanup:
        safe_free(server_socket, sizeof(Socket)); 
        return NULL;
}
