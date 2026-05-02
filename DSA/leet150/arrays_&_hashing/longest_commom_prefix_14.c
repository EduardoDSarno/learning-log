#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    

    size_t first_word_size = strlen(*strs);
    size_t output_index = 0;

    // checks edge case
    if (strsSize == 1) return strdup(strs[0]); // makes a malloc copy

    char *output = malloc(first_word_size + 1); // size of word


   

    for (int i = 0; i < first_word_size; i++)
    {
        for (int j = 1; j < strsSize; j++) { // j to 1 to skip first
            // for each letter in the first word (reference word)
            // we want to check the nth letter in the other words
            if (strs[0][i] == strs[j][i]) {
                //printf("first word char: %c\n", strs[0][i]);
                //printf("matches chars: %c\n", strs[j][i]);
                if(j == strsSize - 1){
                    //printf("here : %c\n",strs[0][i]);
                    
                     output[i] = strs[0][i]; // if we got to the last word
                     output_index++;
                }
            }
            else  {
                output[output_index] = '\0';
                return output;
            }

        }
    }
    output[output_index] = '\0';
    return output;
}
