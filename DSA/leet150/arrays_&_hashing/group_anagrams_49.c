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

Bucket *get(Bucket **hashmap, int key[SIZE_OF_ALPHABET], size_t table_size);
int hash(int frequency[SIZE_OF_ALPHABET], size_t table_size);
void frequency_mapping(char *strs, int freq[SIZE_OF_ALPHABET]);


void insert(char **strings,
            Bucket **hashmap, 
            int key[SIZE_OF_ALPHABET], 
            size_t table_size){

    int index = hash(key, table_size);
    Bucket *new_bucket = get(hashmap, key, table_size);
    
    if (!new_bucket) {
        new_bucket = calloc(1, sizeof(Bucket));
        new_bucket->capacity = 2;
        new_bucket->strings = malloc(sizeof(char *) * new_bucket->capacity);
        memcpy(new_bucket->key, key, sizeof(int) * SIZE_OF_ALPHABET); // can not assign, so copy

        // add to hashmap with collision prevention
        new_bucket->next = hashmap[index];
        hashmap[index] = new_bucket;
    }
    if(new_bucket->capacity == new_bucket->count)
    {
       new_bucket->strings = realloc(new_bucket->strings, sizeof(char *) 
                                    * new_bucket->capacity * 2);

        new_bucket->capacity *= 2;
    }
    new_bucket->strings[new_bucket->count] = *strings;
    new_bucket->count++;


}

Bucket *get(Bucket **hashmap, 
            int key[SIZE_OF_ALPHABET], 
            size_t table_size)
{
    int index = hash(key, table_size);

    Bucket *map = hashmap[index];

    // walk the chain
    while (map != NULL) {
        // memcmp compare 2 blocks of memory 0 if they are identical
         if(memcmp(map->key, key, sizeof(int) * SIZE_OF_ALPHABET) == 0)
        {
            return map;
        }
        map = map->next;
    }

    return NULL;
}

void frequency_mapping(char *strs, int freq[SIZE_OF_ALPHABET]){

    for (int i = 0; strs[i] != '\0'; i++){
        int index = strs[i] - 'a';
        freq[index]++;
    }
}

/* hash function modified to give*/
int hash(int frequency[SIZE_OF_ALPHABET], size_t table_size){
    long h = 0;

    for (int i = 0; i < SIZE_OF_ALPHABET; i++) {
        h = (h * 31 + frequency[i]) % table_size;
    }
    return (int)h; 
}


char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {

    // since we will need a bucket for each string
    Bucket **hashmap = calloc(strsSize, sizeof(Bucket *));
    int freq[SIZE_OF_ALPHABET];

    for (int i = 0 ; i < strsSize; i++) {
        // reset freq to 0 before each word
        memset(freq, 0, sizeof(int) * SIZE_OF_ALPHABET);
        frequency_mapping(strs[i], freq);
        insert(&strs[i], hashmap, freq, strsSize);
    }

    char *** output = calloc(strsSize, sizeof(char **));
    *returnColumnSizes = calloc(strsSize, sizeof(int));
    *returnSize = 0;


    for (int i = 0; i < strsSize; i++) {
        Bucket *map = hashmap[i];
        while (map != NULL) 
        {
            output[*returnSize] = map->strings;
            (*returnColumnSizes)[*returnSize] = map->count;
            (*returnSize)++;
            map = map->next;
        }
    }
    return output;
}