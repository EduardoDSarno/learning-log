#include "sha256.h"
//#include <cstring>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>


int main(){

    // step 1
    unsigned char message[] = "";
    sha_fn(message);
}

int sha256_hash_bytes(const uint8_t *message, size_t message_len_bytes, uint32_t out_H[SHA256_STATE_WORDS])
{
    size_t n_bits = message_size_bits(message_len_bytes);
    size_t k = find_number_of_zeros_needed(n_bits);
    size_t total_bits = padded_message_size_bits(n_bits, k);
    size_t num_blocks = block_count_from_total_bits(total_bits);

    uint8_t *blocks = calloc(total_bits, sizeof(uint8_t));
    if (blocks == NULL) {
        fprintf(stderr, "Failed to allocate %zu bits buffer\n", total_bits);
        return 1;
    }

    if (encode_message((const unsigned char *)message, message_len_bytes, blocks, total_bits) != 0) {
        free(blocks);
        return 1;
    }

    message_schedule(blocks, num_blocks, out_H);
    free(blocks);
    return 0;
}

int sha256_hash_hex(const uint8_t *message, size_t message_len_bytes, char out_hex[SHA_OUT_HEX_RESULT_LENGTH])
{
    uint32_t H[SHA256_STATE_WORDS];
    if (sha256_hash_bytes(message, message_len_bytes, H) != 0) {
        return 1;
    }
    sha256_hex(H, out_hex);
    return 0;
}

int sha256_hash_digest(const uint8_t *message, size_t message_len_bytes, uint8_t out_digest[SHA256_DIGEST_BYTES])
{
    uint32_t H[SHA256_STATE_WORDS];
    if (sha256_hash_bytes(message, message_len_bytes, H) != 0) {
        return 1;
    }

    // Convert H[0..7] words into 32 bytes (big-endian)
    for (size_t i = 0; i < SHA256_STATE_WORDS; i++) {
        out_digest[i * SHA256_WORD_BYTES + 0] = (uint8_t)(H[i] >> 24);
        out_digest[i * SHA256_WORD_BYTES + 1] = (uint8_t)(H[i] >> 16);
        out_digest[i * SHA256_WORD_BYTES + 2] = (uint8_t)(H[i] >> 8);
        out_digest[i * SHA256_WORD_BYTES + 3] = (uint8_t)(H[i] >> 0);
    }
    return 0;
}

int sha_fn(unsigned char message[]){
    // Convenience wrapper for null-terminated text input.
    size_t message_len_bytes = strlen((const char *)message);

    char hex[SHA_OUT_HEX_RESULT_LENGTH];
    if (sha256_hash_hex((const uint8_t *)message, message_len_bytes, hex) != 0) {
        return 1;
    }
    printf("sha256: %s\n", hex);
    return 0;
}
/* This function is a the one responsible for performing the padding of */
int encode_message(const unsigned char message[], size_t message_len_bytes, uint8_t block_bits[], size_t total_bits){
    size_t j = 0;
    size_t message_bits = message_size_bits(message_len_bytes);
    size_t minimum_needed = message_bits + LAST_BIT_TO_APPEND + SIZE_MESSAGE_LENGHT_BLOCK_BIT;

    if (total_bits < minimum_needed) {
        fprintf(stderr, "total_bits (%zu) is too small, need at least %zu\n", total_bits, minimum_needed);
        return 1;
    }

    // step 1: Encode
    // the loop will go through every char inside the message
    for (size_t character_index = 0; character_index < message_len_bytes; character_index++)
    {
        if (j + CHAR_BYTE_SIZE_BITS > total_bits) {
            fprintf(stderr, "Bit buffer overflow while encoding message\n");
            return 1;
        }
        byte_to_bits(message[character_index], &block_bits[j]);
        j += CHAR_BYTE_SIZE_BITS; // move 8 positions so we don't overlap
    }
    //step 2:
    block_bits[j] = LAST_BIT_TO_APPEND; // appending 1 right after message bits

    // step 3 append the original message length at the end of the padded bitstream.
    append_size(block_bits, total_bits, message_bits);

    return 0;
}




// this will Break the message block into 512-bit chunks. and
// loops through each one of them inside the blocks array
void message_schedule(const uint8_t *blocks, size_t num_blocks, uint32_t out_H[SHA256_STATE_WORDS])
{
    for (size_t i = 0; i < SHA_INITIAL_CONSTANTS_LENGHT; i++) {
        out_H[i] = SHA256_H_INIT[i];
    }
    
    for (size_t block_index = 0; block_index < num_blocks; block_index++) 
    {
        size_t block_start = block_index * SIZE_BLOCK_BITS;
        const uint8_t *individual_block = blocks + block_start;
        uint32_t words[NUMBER_OF_WORDS_ARRAY]; // NUMBER_OF_BIT_PER_WORD_ARRAY array words
    
        // Now block_ptr[0..511] is exactly this one block
        expand_message_schedule(individual_block, words);
        compress_message_schedule(out_H, words);

    }
}



// stopped here
void expand_message_schedule(const uint8_t block_bits[SIZE_BLOCK_BITS], 
    uint32_t W[NUMBER_OF_WORDS_ARRAY])
    {
    // so here we have to fill W[0..15] from then block, because
    // a SIZE_BLOCK_BITS bit block = 16chunkcs x 32 bits

    for(int i = 0; i < LENGTH_OF_A_CHUNCK_FROM_THE_BLOCK; i++){

    int start_bit_index = i * NUMBER_OF_BIT_PER_WORD_ARRAY;
    W[i] = bits_to_u32_be(&block_bits[start_bit_index]);

    }

    // Expand W[16..63] using SHA-256 small sigma functions
    for (int t = W_OFF_16; t < NUMBER_OF_WORDS_ARRAY; t++) {
        W[t] = sigma1(W[t - W_OFF_2])
        + W[t - W_OFF_7]
        + sigma0(W[t - W_OFF_15])
        + W[t - W_OFF_16];
    }
}

/* Compression function that will take the SHA constants and perform combinations with W(words)
to provide the compression of the block following expansion*/
void compress_message_schedule(uint32_t H[SHA_INITIAL_CONSTANTS_LENGHT], const uint32_t W[NUMBER_OF_WORDS_ARRAY] ){
    uint32_t v[SHA_INITIAL_CONSTANTS_LENGHT]; // temp array to copy state from H to work w/ them

    // copying the states
    for (size_t i = 0; i < SHA_INITIAL_CONSTANTS_LENGHT; i++) {
        v[i] = H[i];
    }

    for (int t = 0; t < NUMBER_OF_WORDS_ARRAY; t++) {
        uint32_t T1 = v[7] + BIG_SIGMA1(v[4]) + Ch(v[4], v[5], v[6]) + SHA256_K[t] + W[t];
        uint32_t T2 = BIG_SIGMA0(v[0]) + Maj(v[0], v[1], v[2]);

        // shift down (h=g, g=f, f=e, d=c, c=b, b=a)
        v[7] = v[6];
        v[6] = v[5];
        v[5] = v[4];
        v[4] = v[3] + T1;  // e = d + T1
        v[3] = v[2];
        v[2] = v[1];
        v[1] = v[0];
        v[0] = T1 + T2;    // a = T1 + T2

    }

    // Add the compressed chunk to the current hash value
    for (size_t i = 0; i < SHA_INITIAL_CONSTANTS_LENGHT; i++) {
        H[i] += v[i];
    }

}

// receives each groups of words state in chuncks of SHA256_STATE_WORDS size and returns the SHA result on 
// the provided buffer
void sha256_hex(const uint32_t H[SHA256_STATE_WORDS], char out_hex[SHA_OUT_HEX_RESULT_LENGTH])
{
    for (size_t i = 0; i < SHA256_STATE_WORDS; i++) {
        // 8 hex chars per 32-bit word
        snprintf(out_hex + (i * SHA256_WORD_HEX_CHARS), SHA256_WORD_HEX_BUF, "%08x", H[i]);
    }
    out_hex[SHA256_DIGEST_HEX_CHARS] = '\0';
}

void append_size(uint8_t block[], size_t block_size, uint64_t message_size){

    uint8_t message_size_value_bits[SIZE_MESSAGE_LENGHT_BLOCK_BIT];

    // make value_bits be our SIZE_LENGHT_BLOCK_BIT bit block of the decimal number
    value_to_bits( message_size,
                message_size_value_bits,
                   SIZE_MESSAGE_LENGHT_BLOCK_BIT);

    // apend value_bitsin the end of block[]
    size_t start_position = block_size - SIZE_MESSAGE_LENGHT_BLOCK_BIT;

    for(size_t i = 0; i < SIZE_MESSAGE_LENGHT_BLOCK_BIT; i++){
        block[start_position + i]= message_size_value_bits[i];
    }

}


void get_binary_from_int(unsigned int num, uint8_t out_bits[])
{
    value_to_bits((uint64_t)num, out_bits, sizeof(num) * INT_BYTE_SIZE_BITS);
}



// helper function to get decimal to bits
void value_to_bits(uint64_t value, uint8_t out_bits[], unsigned width)
{
    // Writes exactly `width` bits, MSB first.
    for (unsigned k = 0; k < width; k++) {
        unsigned shift = (width - 1U) - k;
        out_bits[k] = (uint8_t)((value >> shift) & 1U);
    }
}

void byte_to_bits(uint8_t value, uint8_t out_bits[CHAR_BYTE_SIZE_BITS])
{
    value_to_bits((uint64_t)value, out_bits, CHAR_BYTE_SIZE_BITS);
}

// this helper is for getting a big-endian bit order, meaning that the first bit is the MSB
uint32_t bits_to_u32_be(const uint8_t *bits32) {

    uint32_t w = 0;
    for (int i = 0; i < NUMBER_OF_BIT_PER_WORD_ARRAY; i++) {
        w = (w << 1) | (uint32_t)(bits32[i] & 1);
    }
    return w;
}

size_t message_size_bits(size_t message_len_bytes)
{
    return message_len_bytes * CHAR_BYTE_SIZE_BITS;
}

size_t find_number_of_zeros_needed(size_t message_bits)
{
    // k such that (message_bits + 1 + k) % 512 == 448
    size_t k = (SIZE_OF_BLOCK_BITS_WITHOUT_MESSAGE_LENGTH - ((message_bits + LAST_BIT_TO_APPEND) % SIZE_BLOCK_BITS) + SIZE_BLOCK_BITS) % SIZE_BLOCK_BITS;
    return k;
}

size_t padded_message_size_bits(size_t message_bits, size_t zero_bits)
{
    return message_bits + LAST_BIT_TO_APPEND + zero_bits + SIZE_MESSAGE_LENGHT_BLOCK_BIT;
}

size_t block_count_from_total_bits(size_t total_bits)
{
    return total_bits / SIZE_BLOCK_BITS;
}
// Will print the messgae in bits 
// for debugging
void print_bits(const uint8_t block[], size_t block_size)
{
    for (size_t i = 0; i < block_size; i++) {
        putchar((int)('0' + block[i]));
    }
    puts("");
}

// this moves bits around like permutation
//sing two different rotates makes each output bit 
// depend on bits from two different original positions
static inline uint32_t rotr32(uint32_t x, unsigned n)
{
    return (x >> n) | (x << (NUMBER_OF_BIT_PER_WORD_ARRAY - n));
}

//Combines those three rearranged versions bit-by-bit, 
// so each output bit becomes the parity of three selected input bits
static inline uint32_t sigma0(uint32_t x)
{
    return rotr32(x, SIGMA0_ROTR_1) ^ rotr32(x, SIGMA0_ROTR_2) ^ (x >> SIGMA0_SHR);
}

//he small sigmas make sure that bits from earlier words spread 
//into many later words in a complex way, instead of W[t] being a simple copy/shift of earlier pieces.
static inline uint32_t sigma1(uint32_t x)
{
    return rotr32(x, SIGMA1_ROTR_1) ^ rotr32(x, SIGMA1_ROTR_2) ^ (x >> SIGMA1_SHR);
}

// math helper functions provided by model based on SHA256 standars for compression logic
uint32_t BIG_SIGMA0(uint32_t x) {
    return rotr32(x, 2) ^ rotr32(x, 13) ^ rotr32(x, 22);
}

uint32_t BIG_SIGMA1(uint32_t x) {
    return rotr32(x, 6) ^ rotr32(x, 11) ^ rotr32(x, 25);
}

// choice helper function
static inline uint32_t Ch(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ ((~x) & z);
}

// maj helper funciton
static inline uint32_t Maj(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}