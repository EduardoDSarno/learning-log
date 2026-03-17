// g++ -o test test.cpp && ./test

#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        /* This approach will be mine second attempt into the problem 
            but this time using 2 pointers left-right insated of binary
            search*/

        int left = 0;
        int right = numbers.size()- 1;
        vector<int> response;

        // through the whole loop
        while (left <= right) {
            
            //printf("left: %d\n", left);
            //printf("right: %d\n", right);
            int sum = numbers[left] + numbers[right];
           // printf("sum %d\n", sum);
            if (sum == target) {
                response.push_back(left + 1);
                response.push_back(right + 1);
                return response;
            }
            // because it is ordered
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }     
            
        }
        return response;
    }
};

int main(void){
    
    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution solution;
    vector<int> sol= solution.twoSum(nums, target);


}