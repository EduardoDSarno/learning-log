/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


// building hashmap

#include "stdio.h"
#include <stdlib.h>
#include <string.h>


typedef struct Buckets // tag name
{
    int value;
    int key;
    struct Buckets *next;


} Buckets;

int hash(int key, size_t table_size){
    return abs(key) % table_size;
}

void insert(int key,
            int value,
            size_t table_size,
            Buckets **hashmap)
{

    // index in the array
    int index = hash(key, table_size);

    // bucket needs to leave on the heap to stay after returns
    // calloc returns a pointer to the memory it just allocated on the heap
    Buckets *new_bucket = calloc(1, sizeof(Buckets));
    new_bucket->key = key;
    new_bucket->value = value;
    
    // to avoid collision
    // tells new_bucket next to point at the current index
    // assing the index to new bucket
    // that way we create a chain on hashmap[index] ex: index.1, index.2 all inside index
    new_bucket->next = hashmap[index];
    hashmap[index] = new_bucket;
}

Buckets *get(int key,
            size_t table_size,
            Buckets **hashmap)
{
    size_t index = hash(key, table_size);
    Buckets *map = hashmap[index];

    // loop throught the maps in the hashmap index (if there are any, and find the value)
    while (map != NULL)
    {
        if(key == map->key) return map;
        map = map->next;
    }
    return NULL; // if none were found
}

int* twoSum(int* nums, int numsSize, int target, int *returnSize) {
    
    Buckets **hashmap = malloc(sizeof(Buckets *) * numsSize);
    memset(hashmap, 0, sizeof(Buckets *) * numsSize);

    // to stay in the heap after returning
    *returnSize = 2;
    int *result = malloc(sizeof(int) * *returnSize);
    
    /* get the complement and insert in the hashmap*/
    for (int i = 0; i < numsSize; i++){

        Buckets *map = (get(nums[i], numsSize, hashmap));
        if(map){ // if found
            result[0] = i;
            result[1] = map->value;
            return result;
        }

        // if not match found yet, keep searching
        int complement = target - nums[i];

        insert(complement, i, numsSize, hashmap);
    }

    return result;
}