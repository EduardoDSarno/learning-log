#include <unordered_set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> seen;


        for (int num : nums) {
            seen.insert(num);
        }

        int current_sequence = 0;
        int max_senquence_len = 0;

        for (int items : seen) {
            // if the item is found
             if (seen.count(items - 1)) {
                ;
             }
             else {
                int j = 0;
                while (seen.count(items + j)) {
                    current_sequence++;
                    j++;
                }
                if (current_sequence > max_senquence_len) max_senquence_len = current_sequence;
                current_sequence = 0;
             }
        }
        return max_senquence_len;
    }
};