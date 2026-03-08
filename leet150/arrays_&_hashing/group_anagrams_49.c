/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26

    
typedef struct Bucket{
    int key[SIZE_OF_ALPHABET];
    int count; // how many strings are in the Bucket
    char **strings;
    int capacity;
    struct Bucket *next;
} Bucket;

int hash(int frequency[SIZE_OF_ALPHABET], size_t table_size);
void frequency_mapping(char *strs, int freq[SIZE_OF_ALPHABET]);


void insert(char **strings,
            Bucket **hashmap, 
            int key[SIZE_OF_ALPHABET], 
            size_t table_size){

    int index = hash(key, table_size);

   Bucket *new_bucket = calloc(1, sizeof(Bucket));

   new_bucket->count = 1;


    // build frequency


    memcpy(new_bucket->key, key, sizeof(int) * SIZE_OF_ALPHABET); // can not assign so copy
    new_bucket->strings = strings;

    new_bucket->next = hashmap[index];
    hashmap[index] = new_bucket;
}

Bucket *get( Bucket **hashmap, 
            int frequency[SIZE_OF_ALPHABET], 
            size_t table_size)
{
    int index = hash(frequency, table_size);
    return hashmap;
}

void frequency_mapping(char *strs, int freq[SIZE_OF_ALPHABET]){

    for (int i = 0; i < SIZE_OF_ALPHABET; i++){
        int index = strs[i] - 'a';
        freq[index]++;
    }
}

/* hash function modified to give*/
int hash(int frequency[SIZE_OF_ALPHABET], size_t table_size){

    int hash = 0;

    for (int i = 0 ; i < SIZE_OF_ALPHABET; i++) {
        hash = hash * 31 + frequency[i];
    }
    return hash % table_size; 
}


char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {

}