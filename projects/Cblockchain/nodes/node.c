#include "node.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    uint8_t pub_key [SIZE_PUB_KEY_BYTES];
    uint8_t priv_key[SIZE_PRIV_KEY_BYTES];   
    uint8_t address [SHA256_DIGEST_BYTES];

    // for TCP Node conneciton

    uint16_t port; // values from 0 -> 65535

    /* Chose for IPV4*/
    uint32_t ipv4;

}Node;

/* use dev/urandom for generating private key
    and then isomg ECDSA bitcoin library to get the pub key
    as well as my sha hashing for the adress*/
Node *node_init(uint8_t pub_key [SIZE_PUB_KEY_BYTES],
                uint16_t port,
                uint32_t ipv4)
{
    Node *new_node = malloc(sizeof(Node));
    
    // open file
    FILE *file =fopen("/dev/urandom", "rd");

    if (file == NULL) {
        fprintf(stderr, "Error opening the file");
        return NULL;
    }

    fread(new_node->priv_key, sizeof(uint8_t), SIZE_PUB_KEY_BYTES, file);
}