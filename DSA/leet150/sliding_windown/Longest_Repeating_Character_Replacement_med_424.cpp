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
#include <algorithm>

//Window - maxCount <= k
using namespace std;

class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        size_t word_s = s.size();

        // start pointers
        char * left  = &s[0];
        

        int freq[26] = {0};

        int max_sequence = 0;

        for (int i  = 0; i < word_s; i++) 
        {
            char * right = &s[i];
            int windown = right - left + 1;
            /* One bug that I was facing in my code was that I was using if/else
                for itens left/right equal or not. But actually the frequency
                array is the one that does this job already, because if they are equal
                soly does not matters that much, what matters more is how many are equal*/
            freq[*right - 'A']++;  
            int max_freq = *max_element(freq, freq + 26);  // recompute from the array

            // if the whole windwo - the max frequent elemtent is smaller than k
            // it just means the windwon is still valid
            // because we could replace k with our value
            // so we check for the opposite (invalidation)
            if(windown -  max_freq > k)
            {
                // when the windown is not valid anymore
                // we need to shrking the windown from left
                freq[*left - 'A']--;  // remove left char from frequency count
                left++;
                windown = right - left + 1;
            }
              
            
            printf("windown_size = %d, from %c, index %ld to %c index %ld\n",
                windown,
                *left, left - &s[0],   // char, then its index
                *right, right - &s[0]  // char, then its index
            );

            if(windown > max_sequence) max_sequence = windown;
        }
        printf("%d\n", max_sequence);
        return max_sequence;
    }
};

int main(void)
{

    char test[] = "AABABBA";
    int k = 1;

    Solution s;

    s.characterReplacement(test, k);
    return 0;
}