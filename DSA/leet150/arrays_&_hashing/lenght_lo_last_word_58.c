// gcc -o test test.c && ./test


#include "stdio.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {

    size_t s_len = strlen(s);

   int i = s_len - 1; // to remove null termitor
   //printf("lenght : %d\n", i);
    while (i >= 0 && isspace(s[i])) {
        i--;
        //printf("here i %d\n", i);
    }

    int start = i;
    //printf("start: %d\n", start);
    while (i >= 0 && !isspace(s[i])) {
        i--;
    }
    //printf("last i: %d\n", i);
    
    return start - i;
}