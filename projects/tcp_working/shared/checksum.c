#include "helpers.h"

/* this function will get the  Pseudo IP heade, TCP header and TCP body add to a buffer and return
    a pointer to this buffer with the formmated data to perfrom checksum*/
uint16_t* format_check_sum(struct tcphdr *header, const uint8_t * message_buffer,  size_t buffer_size,
        const uint32_t ipv4_scr,
        const uint32_t ipv4_dest,
        size_t *out_size_buffer)
{
    size_t size = sizeof(struct tcphdr) +  buffer_size + sizeof(PseudoIpHeader);

    // this should hold the whole lenght of the sum for the calculation.
    uint16_t *temp_buffer = malloc(size + 1); // + 1 for possible allocation of padding
    if (temp_buffer == NULL) {
    fprintf(stderr, "Error allocating memory");
    return NULL;
    }

    // cast temp buffer because with uint16 it will advance 2 bytes foward in the function insated of 1
    memcpy((uint8_t *)temp_buffer, header, sizeof(struct tcphdr));
    memcpy((uint8_t *)temp_buffer + sizeof(struct tcphdr), message_buffer, buffer_size);

    uint16_t segment  = sizeof(struct tcphdr) + buffer_size;
    PseudoIpHeader *pseud_ip_header = psdIpHeader_intit(ipv4_scr, ipv4_dest, IPPROTO_TCP, segment);

    memcpy((uint8_t *)temp_buffer + sizeof(struct tcphdr) +  buffer_size, pseud_ip_header, sizeof(PseudoIpHeader));

    // padding
    if (size % 2 == 1) {
    memset((uint8_t *)temp_buffer + size, 0, 1);
    size+=1;
    }

    free(pseud_ip_header);

    *out_size_buffer = size;
    return temp_buffer;
}

uint16_t check_sum(uint16_t * buffer, size_t * size){

    // now I need to sum the words
    uint32_t sum = 0; // 32 bits so there is no overvlow

    size_t words = *size / 2; // so we loop as if was to 16-bit words insated of bytes

    for (size_t i = 0; i < words; ++i) {

    sum +=buffer[i];
    }

    printf("sum totoal: %d\n", sum);
    // bitwise to moves all the (in big endian) bits to avoid overflow
    while (sum >> 16) // condition will run while there is a over flow
    {
    sum = (sum & 0xFFFF) + (sum >> 16);
    }

    //with new right size
    uint16_t new_sum = sum;
    // fliping bits
    new_sum = ~new_sum;

    // checksum
    return new_sum;

}
