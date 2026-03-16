#include "hash.h"

/* This function will take a new block and the old and it will hash the previous block
    and add the hash to the new block 'previous hash' field
*/
int hash(Block *new_block, Block *prev_block)
{
    short result = 1;

    size_t block_size;
    block_size = serialized_size(prev_block);

    uint8_t *serialized_buffer = malloc(sizeof(uint8_t) * block_size);

     if (serialized_buffer == NULL) {
        fprintf(stderr, " Error: Seralized Buffer is nNULL");
        result = 0; // failure
        goto cleanup;
    }

    // get the block data to be serialized and placed inside the buffer
    if (!serialize(prev_block, 
        serialized_buffer, 
        block_size)){
            fprintf(stderr, "Error: Serialize function Failed");
            result = 0;
            goto cleanup;
        }

    
    // writing the previous hash on new block
    result =  sha256_hash_digest(serialized_buffer,
                     block_size
                    , new_block->previous_hash); 


    cleanup:
        free(serialized_buffer);
        // preventing error message in sucessefull calls
        if(result == 0) fprintf(stderr, "Error: That was a error Hashing your Block");
        return result;
}
