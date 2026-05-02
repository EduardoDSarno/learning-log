#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block{
    char key;
    int value; // how many times have you seen it
    struct Block * next;

} Block;

// t and s have the same length
// no abs() need since is a unsigned char
// just lowercase letter, no tolowercase() required
int hash(size_t strint_length, unsigned char key){

    int index = key * 31 % strint_length;

    return index;
}
Block *get(size_t size, 
            char key,
            Block **hashmap)
{
    int index = hash(size, key);

    Block *map = hashmap[index];

    while (map != NULL)
    {
        if(map->key == key) return map;
        map = map->next;
    }

    return NULL;
    
}
void insert(size_t size, 
            char key,
            Block **hashmap)
{
    int index = hash(size, key);
    
   Block *map = get(size, key, hashmap);

   if(map){
        map->value++;
        return;
   }
   else{
        Block *new_block = calloc(1, sizeof(Block));

        new_block->key = key;
        new_block->value = 1; // value alwasy starts at 1
        //new_block->next unesscessary here already set to null by calloc

        // insert
        // still need the collsion because the length can be smaller than the letters on the alphabet
        // causing some letters to have the same hash
        new_block->next = hashmap[index];
        hashmap[index] = new_block;
   }
   
}


int isAnagram(char* s, char* t) {

    size_t length = strlen(s); // both have the same length
    size_t length2 = strlen(t);

    if(length != length2) return 0; // both lenghts have to be the same
    Block **hashmap = malloc(length * sizeof(Block *));
    memset(hashmap, 0, length * sizeof(Block *)); // deals with garbage
    //Block *map = calloc(length, sizeof(Block));

    for (int i = 0; i < length; i++){
        insert(length, s[i], hashmap);
    }
    for (int i = 0; i < length; i++){

        // search in the hashmap if not there we return 0;
        // since all letters must be there (anagram)
        // if all pass we return 1 (true)

        Block *map = get(length, t[i], hashmap);
        if(!map)
        {
            return 0; // not an anagram
        }
        else // if there's a match verify value
        {
            if(map->value == 0) return 0; // if it is already at 0 means that t has more than s
                                            // not an anagram
            map->value--;
            
        }


    }

    return 1;
}