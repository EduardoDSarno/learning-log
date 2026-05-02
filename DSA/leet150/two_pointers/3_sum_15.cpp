#include <cstddef>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     
        vector<vector<int>> result;

        // sort vec
        sort(nums.begin(), nums.end());

        size_t size = nums.size();
        for (int i = 0; i < size; i++) {
            // fix one number meaning loopign throughout nums and applying to sum

            // The edge case here is to skip the duplicated for i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;


            while (left < right) {
                
                // we need to get the sum of items
                int sum = nums[left] + nums[right] + nums[i];

                if (sum == 0) {
                    // correct triplet
                    vector<int> triplet = {nums[i], nums[left],nums[right]};
                    result.push_back(triplet);

                    // this is because we can not contain duplicate triplets, 
                    // so by having already left and right as know we wouldn't 
                    // have another valid solution since for any nums[i] in the 
                    // loop the triple would be the same
                    left++;
                    right--;
                    

                    // now since it is sorted we still can have cases where we have multiple
                    // duplicated nums on after the other so we must remove the duplicates 
                    // for right and left
                    // also another details is that we must compare the PREVIOUS nums[index]
                    // since we are already ++ above
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if (sum < 0) {
                    // since is sorted we want a higher number if left < 0 so:
                    left++;
                }
                else{
                    right--;
                }

            }

        }
        return result;

    }
};