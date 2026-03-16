#include "serialize.h"


size_t serialize(const Block *block, uint8_t * buffer, size_t buffer_size){

    size_t block_size = serialized_size(block);

    if (buffer == NULL || block_size > buffer_size) {
        return 0; // failure
    }

    size_t offset = 0;

    // copy bytes into buffer per field
    memcpy(offset + buffer,&block->index, sizeof(block->index));
    offset += sizeof(block->index);

    memcpy(offset + buffer,&block->timestamp, sizeof(block->timestamp));    
    offset += sizeof(block->timestamp);

    memcpy(offset + buffer,&block->previous_hash, SHA256_DIGEST_BYTES);
    offset += SHA256_DIGEST_BYTES;

    memcpy(offset + buffer,&block->nounce, sizeof(block->nounce));
    offset+=sizeof(block->nounce);

    /* loop through the transactions memcpy their bytes*/
    for (int i = 0; i < block->transactions_count; i++) {
        memcpy(offset + buffer, &block->transactions[i], sizeof(Transaction));
        offset += sizeof(Transaction);
    }

    return offset; // total bytes written
}


size_t serialized_size(const Block *block){

    size_t size = 0;

    // wire frame it
    size += sizeof(block->index);
    size += sizeof(block->timestamp);
    size += sizeof(block->previous_hash);
    size += sizeof(block->nounce);

    // dynamic transaction size
    size_t transaction_size = serialize_transaciton_size(block);

    size += transaction_size;
    return size;

}

size_t serialize_transaciton_size(const Block * block){

   size_t sum = 0;

   // adding one by one to avoid compiler padding
   // the sizeof(((Transaction*)0) makes the compiler fakes puttinga transaction inside 
   // address 0 to be able to access the field and get it's size
   // since it uses sizeof at compile it does not crash
   sum+= sizeof(((Transaction*)0)->sender_address);
   sum+= sizeof(((Transaction*)0)->receiver_address);
   sum+= sizeof(((Transaction*)0)->signature);
   sum+= sizeof(((Transaction*)0)->timestamp);
   sum+= sizeof(((Transaction*)0)->amount);

   return sum * block->transactions_count;

}
