#include "stdio.h"
#include "stdlib.h"
#include <string.h>


typedef struct Bucket{
    int key;
    struct Bucket *next;
} Bucket;

int hash(size_t set_size, int key){
   return abs(key) % set_size;
}

void insert(Bucket **hashset, int key, size_t set_size){

    int index = hash(set_size, key);

    Bucket *new_bucket = calloc(1, sizeof(Bucket));
    new_bucket->key = key;

    // to avoid collision if there is no next it will just point to NULL
    // unescessary for this program but for good practice
    new_bucket->next = hashset[index];
    hashset[index] =  new_bucket;
}

Bucket *get(Bucket **hashset, int key, size_t set_size){

    int index = hash(set_size, key); 
    Bucket *map = hashset[index];

    while (map != NULL)
    {
        if(key == map->key) return map;
        map = map->next;
    }
    
    return NULL;
}

int containsDuplicate(int* nums, int numsSize) {
    
    Bucket **hashset = malloc(sizeof(Bucket *)  * numsSize); // size of pointer, not Bucket
    memset(hashset, 0,sizeof(Bucket *) * numsSize); // set memory to NULL to avoid mistakes
    // has to match malloc size

    for (size_t i = 0; i < numsSize; i++)
    {
        Bucket *map = get(hashset, nums[i], numsSize);

        if(map){ // if we have the same index (meaning same number)
            return 1;
        }

        insert(hashset, nums[i], numsSize);
    }
    return 0;
    
}