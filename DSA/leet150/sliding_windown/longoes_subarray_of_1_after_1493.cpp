#include <cstddef>
#include <cstdio>
#include <vector>

using namespace std;

class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int left = 0, right = 0, zeros = 0, max_windown = 0;

        size_t len = nums.size();

        while (right < len) 
        {
            if(nums[right] == 0) zeros++;
            while (zeros > 1) 
            {
                if(nums[left] == 0) zeros--;
                left++;
            }
            int windown = right - left + 1;
            if(windown > max_windown) max_windown = windown;
            right++;
        }
        //printf("%d\n", max_windown - 1);
        return max_windown - 1; // -1 from the deleted 0
    }
};

int main(void)
{
    Solution solution;

    vector<int> nums = {1,1,1};


    solution.longestSubarray(nums);
}