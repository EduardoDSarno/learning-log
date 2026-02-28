#include "../block.h"
#include "../SHA_256/sha256.h"


// defined sizes
#define INDEX_BYTE_SERIALIZED_SIZE         4
#define TIMESTAMP_BYTE_SERIALIZED_SIZE     8
#define PREVIOUS_HASH_BYTE_SERIALIZED_SIZE 32
#define NOUNCE_BYTE_SERIALIZED_SIZE        4
#define DATA_LEN_BYTE_SERIALIZED_SIZE      4  // using 4 bytes for data_len (uint32_t)
#define TX_COUNT_BYTE_SERIALIZED_SIZE      4  // 4 bytes for transaction count (uint32_t)
// transactions serialized size depends on the number and format of transactions

size_t serialized_size(const Block *block);
