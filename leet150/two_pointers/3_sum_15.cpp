#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // modfies vector in place
        vector<vector<int>> result;

         sort(nums.begin(), nums.end());

         int size = nums.size() - 1;
         for (int i = 0; i < size; ++i) {
            
            int left = i + 1;
            int right = size;

            while (left < right) {
                int sum = left + right + nums[i];

                if(sum == 0){
                    vector<int> triplet = {nums[left], nums[right], nums[i]};
                    result.push_back(triplet);
                    left += 1;
                    right -= 1;

                    // elimitate duplicates for left
                    while (left < right && nums[left] == nums[left - 1]) {
                        left+=1;
                    }

                    // elimitate duplicates for left
                    while (left < right && nums[right] == nums[right + 1]) {
                        right -= 1;
                    }

                }
                else if (sum < 0) {
                    left+=1;
                }
                else {
                    right-=1;
                }
            }
         }
         return result;
    }
};