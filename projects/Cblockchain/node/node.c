#include "node.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* use dev/urandom for generating private key
    and then isomg ECDSA bitcoin library to get the pub key
    as well as my sha hashing for the adress*/
Node *node_init(uint8_t pub_key [SIZE_PUB_KEY_BYTES],
                uint16_t port,
                uint32_t ipv4)
{
    Node *new_node = malloc(sizeof(Node));
    uint8_t *temp_pubkey = NULL;

    if (new_node == NULL) {
        printf("Failed to generate randomness\n");
        goto cleanup;
    }
    
    // open file
    FILE *file =fopen("/dev/urandom", "rb");

    if (file == NULL) {
        fprintf(stderr, "Error opening the file");
        goto cleanup;
    }

     /*** priv Key Generation ***/
    if(!fread(new_node->priv_key, sizeof(uint8_t), SIZE_PRIV_KEY_BYTES, file)){
        printf("Failed to generate randomness\n");
        goto cleanup;
    }

    // generate pub key
    temp_pubkey = generate_pub_key_helper(new_node->priv_key, file);

    if(temp_pubkey == NULL){
        fprintf(stderr, "error creating temp pub key");
        goto cleanup;
    }

    // copying memory
    memcpy( new_node->pub_key, 
            temp_pubkey, 
            sizeof(uint8_t) * SIZE_PUB_KEY_BYTES);

    // assigning fields
    new_node->port = port;
    new_node->ipv4 = ipv4;

    // generate hash address
    int sha_return = sha256_hash_digest(new_node->pub_key, 
            sizeof(uint8_t) * SIZE_PUB_KEY_BYTES,
                    new_node->address);

    if(!sha_return) {
        fprintf(stderr, "Error on address generation with SHA");
        goto cleanup;
    }

    fclose(file);
    free(temp_pubkey);
    return new_node;

    cleanup:
        if(temp_pubkey != NULL) free(temp_pubkey);
        if(new_node != NULL) free(new_node);
        if(file != NULL)        fclose(file);
        return NULL;

}

uint8_t* generate_pub_key_helper(const uint8_t *priv_key, FILE *file)
{
    // open file
    uint8_t *compressed_pubkey = NULL;

    /* Before we can call actual API functions, we need to create a "context". */
    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
    if (ctx == NULL) {
        printf("Failed to generate randomness\n");
        goto cleanup;
    }

    unsigned char randomize[SIZE_PRIV_KEY_BYTES];
      if(!fread(randomize, sizeof(unsigned char), SIZE_PRIV_KEY_BYTES, file)) {
        printf("Failed to generate randomness\n");
        goto cleanup;
    }

    /*folloing library instructions by randomizing the context*/
    int return_val;
    return_val = secp256k1_context_randomize(ctx,randomize);
    assert(return_val); // verifying

   
    if (!secp256k1_ec_seckey_verify(ctx, priv_key)) {
        printf("Generated secret key is invalid. This indicates an issue with the random number generator.\n");
        goto cleanup;
    }

    /* Public key creation using a valid context with a verified secret key should never fail */
    secp256k1_pubkey pubkey;
    return_val = secp256k1_ec_pubkey_create(ctx, &pubkey, priv_key);
    assert(return_val);

     /* Serialize the pubkey in a compressed form(33 bytes). Should always return 1. */
    size_t len;

    len = SIZE_PUB_KEY_BYTES;
    compressed_pubkey = malloc(sizeof(uint8_t) * len);
    if (compressed_pubkey == NULL) {
        fprintf(stderr, "Failied generating compressed pub key");
        goto cleanup;
    }

    return_val = secp256k1_ec_pubkey_serialize(ctx, compressed_pubkey, &len, &pubkey, SECP256K1_EC_COMPRESSED);
    assert(return_val);
    /* Should be the same size as the size of the output, because we passed a 33 byte array. */
    assert(len == SIZE_PUB_KEY_BYTES);

    secp256k1_context_destroy(ctx);
    return compressed_pubkey;

    cleanup:
        if(compressed_pubkey != NULL) free(compressed_pubkey);
        if(ctx != NULL) secp256k1_context_destroy(ctx);
        return NULL;

}