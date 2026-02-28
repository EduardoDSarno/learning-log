// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.

 

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:

// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.

#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

int lengthOfLastWord(char* s);


int main(void){
    char something[] = "luffy is still joyboy";

    lengthOfLastWord(something);
}

int lengthOfLastWord(char* s) {

    int i = 0;
    // loop through the last word being able to be found, by
    while (s[i] != '\0')
    {
        i++;
    }

    int end_of_string = i;
    printf("end of string: %d\n", end_of_string);
    i--;
    // is it is space we remove until the word
    while (isspace(s[i]))
    {
        i--;
    }

    // last character
    int end_of_last_word = i;


   while (i >= 0 && !isspace(s[i]))
    {
        i--;
    }
    
    printf("end_of_char: %d\n", end_of_last_word);
    printf("i: %d\n", i);
    printf("%d\n", end_of_last_word - i);

    return 0;
    
}