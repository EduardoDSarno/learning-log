#ifndef PSE_IP_HEADER_H
#define PSE_IP_HEADER_H

#include <stdint.h>

typedef struct PseudoIpHeader{

    uint32_t ipv4_scr;
    uint32_t ipv4_dest;
    uint8_t  zero_byte;
    uint8_t  protocol_num; 
    uint16_t tcp_segment_lenght; /* BUG FIX: was uint8_t, RFC 793 pseudo-header needs 16 bits */
} PseudoIpHeader;

PseudoIpHeader *psdIpHeader_intit(uint32_t ipv4_scr,
                            uint32_t ipv4_dest,
                            uint8_t  protocol_num, 
                            uint16_t  tcp_segment_lenght);

#endif
