#include <cstddef>
#include <cstdio>
#include <vector>


using namespace std;
class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        /* a desired valid windown is the widown that has the minimnum number of undisired elements (even)*/
        int left = 0, right = 0, windown_n = 0, odds = 0, total_evens = 0;

        for (int n : nums) 
        {
            if(n % 2 == 0) total_evens++;
        }
        printf("evens: %d\n", total_evens);

        size_t len = nums.size();

        while (right < len) 
        {
            // first lets find the valid windown
            if(nums[right] % 2 == 1) odds++;

            /*The visual way I've seen to do calculations is by for each valid window we devide in blocks
                off what came previous to the windwon as one block, the windown, and what comes next to it as
                the third block. The windown block is immutable since it is the minimun block it means that
                it borders are with valid numbers that if removed will cause to become invalid*/
            if(odds == k)
            {
                // valid windown, now the goal is to find the minimun valid windown
                // and store how many evens happened before it
                int left_evens = 0;
                while (left <= right && nums[left] % 2 == 0)
                {
                    left_evens++;
                    left++;
                }
            
                // we do the same thing we right to see how many evens
                // are after the windown
                int right_evens = 0;
                int next = right + 1;
                while (next < nums.size() && nums[next] % 2 == 0)
                {
                    right_evens++;
                    next++;
                }

                // calculate
                windown_n += (left_evens + 1) * (right_evens + 1);

                // after computing we want to pass this windown and it will always be a odd in the border
                // left of a valid windown, that's why a check is unescessary
                left++;
                odds--;
            }
            right++;
        }
        printf("%d\n", windown_n);
        return windown_n;
    }
};

int main(void)
{
    Solution solution;

    vector<int> nums = {1,1,2,1,1};
    int k = 3;

    solution.numberOfSubarrays(nums, k);
}