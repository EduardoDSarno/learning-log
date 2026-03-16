#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Set{
    int key;
    struct Set *next;

} Set;



int hash(size_t table_size, int key) {
    // Handle negatives properly with unsigned math
    unsigned int k = (unsigned int)key;
    k = ((k >> 16) ^ k) * 0x45d9f3b;
    k = ((k >> 16) ^ k) * 0x45d9f3b;
    k = (k >> 16) ^ k;
    return k % table_size;
}

/* this function will get the set of the key we are looking at 0(1)*/

Set *get(Set **hashset, size_t table_size, int key){

    int index = hash(table_size, key);


    Set *set = hashset[index];

    // diving into the collison if there are
    while (set != NULL) {
        
        // compare the key param with set key 
         if(set->key == key)
        {
            return set;
        }
        set = set->next;
    }
    return NULL;
}

void insert(Set **hashset, int key, size_t table_size){

    int index = hash(table_size, key);

    

    Set *new_set = get(hashset, table_size, key);

    if (!new_set) {
        // if we don't get anything we allocate memory
        // and build a new set
         new_set = calloc(1, sizeof(Set));
         new_set->key = key;

        // avoid collision
        new_set->next = hashset[index];

        // this works because if hashset[index] is null our new set just point to null
        // which is normal
        hashset[index] = new_set;
    }
     
}
int longestConsecutive(int* nums, int numsSize) {

    size_t table_size = numsSize * 10 + 7; // to avoid a bunch of collisions

    Set **hashset = calloc(table_size, sizeof(Set *));
    // for the first loop we insert in the hashset O(n)
    for (int i = 0; i < numsSize; ++i) {
        insert(hashset, nums[i], table_size);
    }

    size_t curr_sequence = 0; // minimun sequence is alwasy 1
    int max = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        
        // if num[i] - 1 does not exits, meaning that we started a sequence
        if (!get(hashset, table_size, nums[i] -  1)) {
            
            int j = 0;
            // while there is another next number we keep going
            while (get(hashset, table_size, nums[i] + j)) 
            {
              curr_sequence++;
               j++;
            }      
            
            if (curr_sequence > max) {
                max = curr_sequence;
            }
            curr_sequence = 0;
        }
    }
     // free everything
    for (size_t i = 0; i < table_size; i++) {
        Set *node = hashset[i];
        while (node) {
            Set *tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(hashset);
    return max;
}
