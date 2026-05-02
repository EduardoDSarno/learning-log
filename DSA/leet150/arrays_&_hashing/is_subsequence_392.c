#include <stddef.h>
#include <stdio.h>
#include <string.h>
int isSubsequence(char* s, char* t) {
    
    // firsr check if s is smaller or equal to t since it must be subsequent
    size_t length_s = strlen(s);
    size_t length_t = strlen(t);
    size_t lenght_counter = 0;
    int match_index = -1;

    if (length_s > length_t) return 0;

    for (int i = 0; i < length_s; i++) {
        
        // try to match
        for (int j = 0; j < length_t;j++){
            if(s[i] == t[j] && match_index < j)// match
            {

                match_index = j;
                lenght_counter++;

                break;
            } 
        }
    }
    if (lenght_counter == length_s){
        return 1;
    } 
    else {
        return 0;
    }
    
}