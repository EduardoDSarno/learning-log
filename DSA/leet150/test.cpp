// g++ -o test test.cpp && ./test


#include <cstddef>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
    public:
        int characterReplacement(string s, int k) {
            
        int left  = 0;
        size_t size = s.length();

        int frequency[26] = {0};
        int most_frequnt_char_index = 0;
        int result = 0;

        for (int right = 0; right < size; ++right) {
            
            int windown_size = 0
            ; 
            int c = 0;

            c = toupper(s[right]) - 'A';
            frequency[c]++;

            if (frequency[most_frequnt_char_index] < frequency[c]) 
            {
                most_frequnt_char_index = c;
            }

            // check if valid
            while(windown_size - frequency[most_frequnt_char_index] > k && left <= right){
                
                c = toupper(s[left]) - 'A';
                frequency[c]--;
                left++;
            }
            windown_size = right - left + 1; 
        
            if(windown_size > result) result = windown_size;
        }
        return result;
    }
};

int main(void){

    char test[] = "AABABBA";
    int k = 1;

    Solution s;

    s.characterReplacement(test, k);
    return 0;
}