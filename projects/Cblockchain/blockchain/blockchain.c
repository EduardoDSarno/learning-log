#include "blockchain.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BlockChain{

    Block * genesis_block;
    Block * last_block;
    size_t block_count;

    // pointer to an array of SHA256_DIGEST_BYTES bytes
    uint8_t (* hash_array) [SHA256_DIGEST_BYTES]; 

} BlockChain;

BlockChain *init(){

    uint8_t temp_hash[SHA256_DIGEST_BYTES] = {0};

    // genesis block
    Block *new_block = NULL;
    new_block = malloc(sizeof(Block));

    if(new_block == NULL){
        fprintf(stderr, "Error: Creation of new block failed in Blockchain Init");
        goto cleanup;
    }

        new_block = block_init(
        0, // index
        time(NULL), // timestamp
        temp_hash,
        0, // nounce
        NULL, // transactions
        0 // t_count
    );

    BlockChain *c_chain = NULL;
    c_chain = malloc(sizeof(BlockChain));

    if(c_chain == NULL){
        fprintf(stderr, "Error: Creation of new blockchain failed in Blockchain Init");
        goto cleanup;
    }
    c_chain->genesis_block = new_block;
    c_chain->last_block = new_block;
    c_chain->block_count = 1;
    // leaves on the heap, relloc for every new block
    c_chain->hash_array = NULL;
    c_chain->hash_array = malloc(SHA256_DIGEST_BYTES * sizeof(uint8_t));

    if(c_chain->hash_array == NULL){
        fprintf(stderr, "Error: Creation of new hash array failed in Blockchain Init");
        goto cleanup;
    }

    return c_chain;

    // freeing from inside out
    cleanup:
        if(c_chain != NULL) free(c_chain->hash_array);
        free(c_chain);
        free(new_block);
        return NULL;
}