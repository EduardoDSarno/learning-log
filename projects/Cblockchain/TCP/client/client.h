#include "../socket/socket.h"
#include <stdint.h>
#include "../../utils/utils.h"
#include <stddef.h>
#include "../../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>

typedef enum {
    
    CONNECTED,
    NOT_CONNECTED

}ClientState;


typedef struct TCPClient{

    Socket server_socket;
    Socket client_socket;
    ClientState state;

} TCPClient;

int client_connect( TCPClient * client, const uint16_t server_port, const uint32_t server_ipv4);
TCPClient *client_init(const uint16_t client_port, const uint32_t client_ipv4);