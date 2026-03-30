#include "pseIPHeader.h"
#include <stdio.h>
#include <stdlib.h>

PseudoIpHeader *psdIpHeader_intit(uint32_t ipv4_scr,
                            uint32_t ipv4_dest,
                            uint8_t  protocol_num, 
                            uint16_t  tcp_segment_lenght)
{

    PseudoIpHeader *new = malloc(sizeof(PseudoIpHeader));

    if (new == NULL) {
        fprintf(stderr, "error allocating memory");
        return NULL;
    }

    new->ipv4_scr = ipv4_scr;
    new->ipv4_dest = ipv4_dest;
    new->zero_byte = 0;
    new->protocol_num = protocol_num;
    new->tcp_segment_lenght = tcp_segment_lenght;

    return new;
}
