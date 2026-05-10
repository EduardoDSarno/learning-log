#include <cstddef>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) 
        {
            size_t len = nums.size();
            int left = 0, right = 0, sum = 0, windown = 0, min_windown = len, check_sum = 0;
            while (right < len) 
            {
                sum += nums[right];
                check_sum += nums[right];
                right++;

                while (sum >= target) 
                {   
                    sum -= nums[left];
                    left++;

                    windown = right - left + 1;
                    if( windown < min_windown) min_windown = windown;
                }
                
                
            }
            if(check_sum < target) return 0;
            printf("%d\n", min_windown);
            return  min_windown;
            
        }
    };


int main (void)
{
    Solution solution;

    vector<int> arr = {1,1,1,1,1,1,1,1};

    solution.minSubArrayLen(5, arr);
}
