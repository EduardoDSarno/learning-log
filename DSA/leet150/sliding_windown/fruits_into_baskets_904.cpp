#include <cstddef>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution 
{
    public:
        int totalFruit(vector<int>& fruits) 
        {
            /* Find the contigous subarray with at most 2 elements*/

            int left = 0, right = 0, windown = 0, max_windown = 0;
            unordered_map<int, int> nums;
            size_t len = fruits.size();

            while (right < len) 
            {
                
            
                // add fruit if not existed
                nums[fruits[right]]++;

                // shirnk the windown if it becoems invalid
                while (nums.size() > 2)
                {
                    nums[fruits[left]]--;

                    if (nums[fruits[left]] == 0)
                    {
                        nums.erase(fruits[left]);
                    }

                    left++;
                }

                // calcuate
                windown = right - left + 1;
                if(windown > max_windown) max_windown = windown;
                printf("we are at %d, index %d. Windown is %d, max windown is: %d, the fruits size is: %lu\n", fruits[right], right, windown, max_windown, nums.size());
                // advance
                right++;
            }
            printf("%d\n", max_windown);
            return max_windown;
        }
    };

int main(void)
{
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};

    Solution solution;

    solution.totalFruit(fruits);
}