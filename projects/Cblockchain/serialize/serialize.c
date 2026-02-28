#include "header.h"

/*
This function will return the size of bytes written in buffer
it takes a memery pointer (buffer)
 and the block pointer to avoidn copyig entire structure
 it also takes buffer size so the function will know how big the buffer is*/
size_t serialize(const Block *block, 
                 uint8_t *buffer,
                 size_t buffer_size)
{
    size_t block_size = serialized_size(block);

    
}

/* Here to get the size we are adding the fixed length in bytes of some fields
for trasnaction size as well (as a second layer) and passing data length
the currently only variable one*/
size_t serialized_size(const Block *block){
    size_t size = 0;

    // Total size of all serialized transactions
    size_t transactions_size = (size_t)block->transactions_count * 
                                       TRANSACTION_SERIALIZED_SIZE;

    size = INDEX_BYTE_SERIALIZED_SIZE         // index
         + TIMESTAMP_BYTE_SERIALIZED_SIZE     // timestamp
         + PREVIOUS_HASH_BYTE_SERIALIZED_SIZE // previous_hash
         + NOUNCE_BYTE_SERIALIZED_SIZE        // nounce
         + DATA_LEN_BYTE_SERIALIZED_SIZE      // data_len
         + block->data_length                 // actual data bytes
         + TX_COUNT_BYTE_SERIALIZED_SIZE      // number of transactions
         + transactions_size; // all transactions

    return size;
}



