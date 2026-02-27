#ifndef SHA256_H
#define SHA256_H

#include <stddef.h>
#include <stdint.h>

// In C we use ~ for complement A', ^ for XOR.
#define XOR(a,b)     a^b
#define AND(a,b)     (a & b)
#define OR(a,b)      (a | b)

#define CHAR_BYTE_SIZE_BITS 8
#define INT_BYTE_SIZE_BITS 8
#define CHAR_BYTE_LENGHT 7 // starting from 0

#define SIZE_BLOCK_BYTE 64
#define SIZE_MESSAGE_LENGHT_BLOCK_BIT 64
#define LAST_BIT_TO_APPEND 1

#define SIZE_BLOCK_BITS (SIZE_BLOCK_BYTE * CHAR_BYTE_SIZE_BITS)
#define SIZE_OF_BLOCK_BITS_WITHOUT_MESSAGE_LENGTH (SIZE_BLOCK_BITS - SIZE_MESSAGE_LENGHT_BLOCK_BIT)

// SHA-256 initial hash value (H0..H7)
#define SHA256_STATE_WORDS 8
// 256-bit digest size
#define SHA256_DIGEST_BYTES 32
#define SHA256_WORD_BYTES 4
static const uint32_t SHA256_H_INIT[SHA256_STATE_WORDS] = {
    0x6a09e667u, 0xbb67ae85u, 0x3c6ef372u, 0xa54ff53au,
    0x510e527fu, 0x9b05688cu, 0x1f83d9abu, 0x5be0cd19u
};

// Words scheduler
#define NUMBER_OF_WORDS_ARRAY 64
#define NUMBER_OF_BIT_PER_WORD_ARRAY 32
#define LENGTH_OF_A_CHUNCK_FROM_THE_BLOCK 16

// Small sigma functions rotation/shift constants (SHA-256 message schedule)
#define SIGMA0_ROTR_1 7
#define SIGMA0_ROTR_2 18
#define SIGMA0_SHR    3

#define SIGMA1_ROTR_1 17
#define SIGMA1_ROTR_2 19
#define SIGMA1_SHR    10

// Message schedule recurrence offsets
#define W_OFF_2   2
#define W_OFF_7   7
#define W_OFF_15  15
#define W_OFF_16  16

#define SHA_INITIAL_CONSTANTS_LENGHT 8
// SHA-256 digest formatting (hex)
// 256-bit digest = 32 bytes = 64 hex chars
#define SHA256_WORD_HEX_CHARS 8
#define SHA256_DIGEST_HEX_CHARS (SHA256_STATE_WORDS * SHA256_WORD_HEX_CHARS)
#define SHA256_WORD_HEX_BUF (SHA256_WORD_HEX_CHARS + 1) // +1 for '\0' in snprintf
#define SHA_OUT_HEX_RESULT_LENGTH (SHA256_DIGEST_HEX_CHARS + 1) // +1 for final '\0'

// SHA-256 round constants K[0..63]
static const uint32_t SHA256_K[NUMBER_OF_WORDS_ARRAY] = {
    0x428a2f98u, 0x71374491u, 0xb5c0fbcfu, 0xe9b5dba5u,
    0x3956c25bu, 0x59f111f1u, 0x923f82a4u, 0xab1c5ed5u,
    0xd807aa98u, 0x12835b01u, 0x243185beu, 0x550c7dc3u,
    0x72be5d74u, 0x80deb1feu, 0x9bdc06a7u, 0xc19bf174u,
    0xe49b69c1u, 0xefbe4786u, 0x0fc19dc6u, 0x240ca1ccu,
    0x2de92c6fu, 0x4a7484aau, 0x5cb0a9dcu, 0x76f988dau,
    0x983e5152u, 0xa831c66du, 0xb00327c8u, 0xbf597fc7u,
    0xc6e00bf3u, 0xd5a79147u, 0x06ca6351u, 0x14292967u,
    0x27b70a85u, 0x2e1b2138u, 0x4d2c6dfcu, 0x53380d13u,
    0x650a7354u, 0x766a0abbu, 0x81c2c92eu, 0x92722c85u,
    0xa2bfe8a1u, 0xa81a664bu, 0xc24b8b70u, 0xc76c51a3u,
    0xd192e819u, 0xd6990624u, 0xf40e3585u, 0x106aa070u,
    0x19a4c116u, 0x1e376c08u, 0x2748774cu, 0x34b0bcb5u,
    0x391c0cb3u, 0x4ed8aa4au, 0x5b9cca4fu, 0x682e6ff3u,
    0x748f82eeu, 0x78a5636fu, 0x84c87814u, 0x8cc70208u,
    0x90befffau, 0xa4506cebu, 0xbef9a3f7u, 0xc67178f2u
};

void expand_message_schedule(const uint8_t block_bits[SIZE_BLOCK_BITS], uint32_t W[NUMBER_OF_WORDS_ARRAY]);
void message_schedule(const uint8_t *blocks, size_t num_blocks, uint32_t out_H[SHA256_STATE_WORDS]);

size_t message_size_bits(size_t message_len_bytes);
size_t find_number_of_zeros_needed(size_t message_bits);
size_t padded_message_size_bits(size_t message_bits, size_t zero_bits);
size_t block_count_from_total_bits(size_t total_bits);
uint32_t bits_to_u32_be(const uint8_t *bits32);

int encode_message(const unsigned char message[], size_t message_len_bytes, uint8_t block_bits[], size_t total_bits);
void append_size(uint8_t block[], size_t block_size, uint64_t message_size);
void get_binary_from_int(unsigned int num, uint8_t out_bits[]);
void value_to_bits(uint64_t value, uint8_t out_bits[], unsigned width);
void byte_to_bits(uint8_t value, uint8_t out_bits[CHAR_BYTE_SIZE_BITS]);
void print_bits(const uint8_t block[], size_t block_size);

// sigma calcualtion
static inline uint32_t rotr32(uint32_t x, unsigned n);
static inline uint32_t sigma0(uint32_t x);
static inline uint32_t sigma1(uint32_t x);
uint32_t BIG_SIGMA0(uint32_t x);
uint32_t BIG_SIGMA1(uint32_t x);
static inline uint32_t Maj(uint32_t x, uint32_t y, uint32_t z);
static inline uint32_t Ch(uint32_t x, uint32_t y, uint32_t z);

// finalzing sha
void sha256_hex(const uint32_t H[SHA256_STATE_WORDS], char out_hex[SHA_OUT_HEX_RESULT_LENGTH]);
void compress_message_schedule(uint32_t H[SHA_INITIAL_CONSTANTS_LENGHT], const uint32_t W[NUMBER_OF_WORDS_ARRAY] );

// Public API (recommended for external files):
// - hash arbitrary bytes (not only null-terminated strings)
// - return either the raw state words or the final hex digest string
int sha256_hash_bytes(const uint8_t *message, size_t message_len_bytes, uint32_t out_H[SHA256_STATE_WORDS]);
int sha256_hash_digest(const uint8_t *message, size_t message_len_bytes, uint8_t out_digest[SHA256_DIGEST_BYTES]);
int sha256_hash_hex(const uint8_t *message, size_t message_len_bytes, char out_hex[SHA_OUT_HEX_RESULT_LENGTH]);



int sha_fn(unsigned char message[]); 

#endif // SHA256_H

