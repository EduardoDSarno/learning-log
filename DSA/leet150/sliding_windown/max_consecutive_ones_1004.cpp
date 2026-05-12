#include <cstdio>
#include <vector>

using namespace std;
class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int right = 0, left = 0, ones = 0, max_windown = 0;
        
        size_t len = nums.size();

        while(right < len)
        {
            int windown = right - left + 1;
            if(nums[right] == 1) ones++;

            while(windown - ones > k && left <= right)
            {
               
                if(nums[left] == 1) ones--;
                left++;   
                windown = right - left + 1;
            }

            if(windown > max_windown) 
            {
                //printf("from index %d to %d, max windonw is: %d\n", left, right, max_windown);
                max_windown = windown;
            }
            right++;
            
            
        }
        //printf("%d\n", max_windown);
        return max_windown;
    }
};

int main(void)
{
    Solution solution;

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    solution.longestOnes(nums, k);
}