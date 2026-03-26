#include <stdint.h>
#include "../SHA_256/sha256.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include </opt/homebrew/include/secp256k1.h>



#define SIZE_PUB_KEY_BYTES 33
#define SIZE_PRIV_KEY_BYTES 32

uint8_t* generate_pub_key_helper(const uint8_t *priv_key, FILE *file);

typedef struct Node {

    uint8_t pub_key [SIZE_PUB_KEY_BYTES];
    uint8_t priv_key[SIZE_PRIV_KEY_BYTES];   
    uint8_t address [SHA256_DIGEST_BYTES];

    // for TCP Node conneciton

    uint16_t port; // values from 0 -> 65535

    /* Chose for IPV4*/
    uint32_t ipv4;

}Node;