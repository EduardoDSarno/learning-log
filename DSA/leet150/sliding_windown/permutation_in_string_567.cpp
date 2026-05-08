#include <cstddef>
#include <cstdio>
#include <string>

using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        size_t windown_req_size = s1.size();
        size_t lenght = s2.size();
        /* The way to identify a permuation can it be by,
            it's lenght on how many characters of a certain type it
            has*/

        int frequency[26] = {0};
        for (char l : s1) 
        {
            frequency[l - 'a']++;
        }

        // start in the beginning
        char * left  = &s2[0];
        char * right = left;
        int freq[26] = {0};
        bool found = false;

        while (right != &s2[lenght] && left != &s2[lenght]) 
        {
            int windown = right - left + 1;
            
            
            freq[*right - 'a']++;


            if (windown > windown_req_size) 
            {
                freq[*left - 'a']--; // remove from frequency
                left++;
            }
    
            windown = right - left + 1;
            if(windown == windown_req_size)
            {
                // comparing freqeuncy array to see if they match
                if (memcmp(frequency, freq, 26 * sizeof(int)) == 0)
                {
                    found = true;
                    break;
                }
            }
            right++;
        } 
        //printf("%d\n", found);
        return found;
    }
};

int main(void)
{
    string s1 = "adc";
    string s2 = "dcda";

    Solution solution;

    solution.checkInclusion(s1, s2);

}


