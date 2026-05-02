#include <cstddef>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            
           vector<unordered_set<char>> result;

           int bucket_index = 0;
           int count = 0;
           int max = 0;
            for (char const c : s) 
            {

                // if not found
                if (result[bucket_index].count(c) == 0) {
                    result[bucket_index].insert(c);
                    count++;
                }
                else // if found
                {
                    max = count;
                    bucket_index++; // increment the bucket
                    result[bucket_index].insert(c);
                    count = 0;
                }

            }

            return max;
        }
};