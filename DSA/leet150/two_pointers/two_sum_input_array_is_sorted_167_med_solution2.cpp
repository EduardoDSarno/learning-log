
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        /* This approach will be mine second attempt into the problem 
            but this time using 2 pointers left-right insated of binary
            search*/

        int *left = &numbers[0];
        int *right = &numbers[numbers.size()- 1];
        vector<int> response;

        // through the whole loop
        while (*left <= *right) {
            
            int sum = numbers[*left] + numbers[*right];
            printf("sum %d\n", sum);
            if (sum == target) {
                response[0] = *left + 1;
                response[1] = *right + 1;
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