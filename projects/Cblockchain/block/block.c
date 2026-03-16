#include "Block.h"

// function to initilize block, it will return block
// instaed of void
Block block_init(
    uint32_t index,
    uint64_t timestamp,
    const uint8_t previous_hash[SHA256_DIGEST_BYTES],
    uint32_t nounce,
    const Transaction *transactions,
    size_t transactions_count)
{
    Block block;
    block.index = index;
    block.timestamp = timestamp;

    // copies bytes into the array, no need to assign it
    memcpy(block.previous_hash, previous_hash, SHA256_DIGEST_BYTES);

    block.nounce = nounce;
    block.transactions = transactions;
    block.transactions_count = transactions_count;

    return block;
}
