// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.


// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

#include <cstddef>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>

//Window - maxCount <= k
using namespace std;

class Solution {
    public:
        int characterReplacement(string s, int k) {
            
        int left  = 0;
        size_t size = s.length();
        int frequency[26];
        int most_frequnt_char_index = 0;
        int result = 0;

        for (int right = 0; right < size; ++right) {
            
            int windown_size = right - left + 1; 
            int c = 0;

            c = s[right] - 'A';
            frequency[c]++;

            if (frequency[most_frequnt_char_index] < frequency[c]) 
            {
                most_frequnt_char_index = c;
            }

            // check if valid
            while(windown_size - frequency[most_frequnt_char_index] > k){
                
                c = s[left] - 'A';
                frequency[c]--;
                left++;
            }
                
            int temp = frequency[most_frequnt_char_index] + k;
            if(temp > result) result = temp;
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