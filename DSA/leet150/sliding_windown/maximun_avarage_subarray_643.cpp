#include <cstddef>
#include <cstdio>
#include <vector>

using namespace std;

class Solution 
{
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int left = 0, right = 0;
        size_t len = nums.size();
        
        double max_avr = (double)INT_MIN;
        double sum = 0.0;
        while(right < len)
        {
            int w = right - left + 1;
            if (w > k) 
            {
                sum -= nums[left];
                left++;
                w--;
            }
            sum += nums[right];
            
            //printf("w: %d, from %d to %d\n", w, nums[left], nums[right]);
            if(w == k)
            {
                // compute
                //printf("sum: %f w: %d\n",sum,w);
                double avg = sum / w;
                if(avg > max_avr) max_avr = avg; 
            }
            
            right++;
        }
        return max_avr;
    }
};

int main (void)
{

    Solution solution;

    vector<int> nums = {-1};
    int k = 1;

    solution.findMaxAverage(nums, k);
}