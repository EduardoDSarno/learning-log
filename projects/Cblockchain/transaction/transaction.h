#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <stdint.h>
#include <stdlib.h>
#include "../SHA_256/sha256.h"

#define SIGNATURE_LENGTH_BYTES 64
#define ADDRESS_LENGTH_BYTES 32

// Serialized sizes (for wire/disk format)
#define TX_TIMESTAMP_BYTES 8   // uint64_t
#define TX_AMOUNT_BYTES 8     // uint64_t
#define TRANSACTION_SERIALIZED_SIZE / (SHA256_DIGEST_BYTES * 2 + SIGNATURE_LENGTH_BYTES + TX_TIMESTAMP_BYTES + TX_AMOUNT_BYTES)

// Minimal transaction model (learning version)
// this __attribute__((packed)) is a GCC/Clang compiler directive that tells the compiler 
// to lay out the struct in memory with no padding bytes between fields.
typedef struct __attribute__((packed)) Transaction {
    uint8_t sender_address[SHA256_DIGEST_BYTES];
    uint8_t receiver_address[SHA256_DIGEST_BYTES];
    uint8_t signature[SHA256_DIGEST_BYTES];
    uint64_t timestamp;
    uint64_t amount;
} Transaction;



#endif

