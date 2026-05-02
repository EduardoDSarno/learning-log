#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;
        int max = 0;
        
        while (left < right) {
            
            /* getting the minimun between them
                because it is whe max water it can be filled
                and multiplying by it's distance to get the arean*/
            int h  = min(height[left], height[right]);
            int dist = right - left;
            int sum  = h * dist;

            if(height[left] < height[right]){
                left++;
            }
            else {
                right--;
            }
            if (sum > max) max = sum;

        }
        return max;
    }
};

int main(void){
    vector<int> array = {1,8,6,2,5,4,8,3,7};
    
    Solution solution;

    printf("%d",solution.maxArea(array));
}