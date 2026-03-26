#include <stdint.h>

typedef struct Socket{
    uint16_t port;
    uint32_t ipv4;
    int file_descriptor_index; 

}  Socket;


// Will return a pointer of the new socket created
Socket *socket_init(const uint16_t, const uint32_t);