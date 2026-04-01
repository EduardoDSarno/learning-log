#include <stddef.h>
#include <string.h>
int characterReplacement(char* s, int k) {
    
    int left  = 0;
    size_t size = strlen(s);

    for (int right = 0; right < size; ++right) {
        
        int windown_size = right - left;
        int most_frequnt_char = 0;

        if (s[left] == s[right]) {
            most_frequnt_char++;
        }
    }
}