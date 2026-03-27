#include "blockchain.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




BlockChain *init(){

    uint8_t init_hash[SHA256_DIGEST_BYTES] = {0};
    uint32_t init_index = 0;

    // genesis block
    Block *new_block = NULL;    

    new_block = block_init
    (
    init_index, // index
    time(NULL), // timestamp
    init_hash,
    0, // nounce
    NULL, // transactions
    0 // t_count
    );

    if(new_block == NULL)
    {
        fprintf(stderr, "Error: Creation of new block failed in Blockchain Init");
        goto cleanup;
    }

    BlockChain *c_chain = NULL;
    c_chain = safe_malloc(sizeof(BlockChain));

    if(c_chain == NULL){
        fprintf(stderr, "Error: Creation of new blockchain failed in Blockchain Init");
        goto cleanup;
    }
    c_chain->genesis_block = new_block;
    c_chain->last_block = new_block;

    c_chain->blocks = safe_malloc(sizeof(Block *));
    if (c_chain->blocks == NULL) {
        fprintf(stderr, "Error: Creation of blocks failed");
        goto cleanup;
    }
    c_chain->blocks[init_index] = new_block;


    c_chain->block_count = 1;
    // leaves on the heap, relloc for every new block
    c_chain->hash_array = NULL;
    c_chain->hash_array = safe_malloc(SHA256_DIGEST_BYTES * sizeof(uint8_t));

    if(c_chain->hash_array == NULL){
        fprintf(stderr, "Error: Creation of new hash array failed in Blockchain Init");
        goto cleanup;
    }

    return c_chain;

    // freeing from inside out
    cleanup:
        if(c_chain != NULL) 
        {
            safe_free(c_chain->hash_array, SHA256_DIGEST_BYTES * sizeof(uint8_t));
            safe_free(c_chain->blocks, sizeof(Block *));
        }
        safe_free(c_chain, sizeof(BlockChain));
        safe_free(new_block, sizeof(Block));
        return NULL;
}

/* This function will receive the new block and blockchain
    -will realloc memory for hash_array 
    -will hash the old block and add to it
    -and increment count
    - returning 1,0 for success/failure
    */
int inser_block(Block * new_block, BlockChain* blockchain){

    void *temp_blocks = safe_realloc(blockchain->blocks,
                                     sizeof(Block *) * (blockchain->block_count + 1),
                                     sizeof(Block *) * blockchain->block_count);

    if (temp_blocks == NULL) {
        fprintf(stderr, "Error: An error occurred when trying to reallocate memory for new block");
        return 0;
    }
    blockchain->blocks = temp_blocks;
    blockchain->blocks[blockchain->block_count] = new_block;
    
    void *temp_hash_array = safe_realloc(blockchain->hash_array,
                        (blockchain->block_count + 1) * SHA256_DIGEST_BYTES * sizeof(uint8_t),
                        blockchain->block_count * SHA256_DIGEST_BYTES * sizeof(uint8_t));

    if (temp_hash_array == NULL){
        fprintf(stderr, "Error: An error occurred when trying to reallocate memory for hashing");
        return 0;
    }
    blockchain->hash_array = temp_hash_array;
    memcpy(blockchain->hash_array[blockchain->block_count], 
            new_block->previous_hash, SHA256_DIGEST_BYTES);

    hash(new_block, blockchain->last_block);

    blockchain->last_block = new_block;
    blockchain->block_count++;

    return 1;
}

 /* 
My current implementation is just a cover so I can continue, but the future
Todo here we have to implement a hashmap inside the blockchain to grab blocks at O(1)
*/

Block* get_block(size_t index, const BlockChain *blockchain )
{
    return blockchain->blocks[index];
}
