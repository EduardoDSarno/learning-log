#include "block.h"
#include "../utils/utils.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// function to initilize block, it will return block
// instaed of void
Block *block_init(
    uint32_t index,
    uint64_t timestamp,
    const uint8_t previous_hash[SHA256_DIGEST_BYTES],
    uint32_t nounce,
    const Transaction *transactions,
    size_t transactions_count)
{
    Block *block = NULL;
    block = safe_malloc(sizeof(Block));

    if(block == NULL){
        fprintf(stderr, "Erro building the block, memory allocated is null");
        goto cleanup;
    }
    block->index = index;

    if (timestamp == 0) {
        timestamp = time(NULL);
        fprintf(stderr, "Warning: your timestamp was initliazes as 0. it will be automatically set to %llu", timestamp);    
        
    }
    block->timestamp = timestamp;  
    

    // copies bytes into the array, no need to assign it
    memcpy(block->previous_hash, previous_hash, SHA256_DIGEST_BYTES);

    block->nounce = nounce;
    block->transactions = transactions;
    block->transactions_count = transactions_count;

    return block;

    cleanup:
        safe_free(block, sizeof(Block));
        return NULL;

}
