// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <functional>
#include <iostream>
#include <ostream>
#include <stddef.h>
#include <vector>
#include <algorithm>

using namespace std;
int max_sum(vector<int> nums);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int tests;

    cin >> tests;

    // read first line
    for(int i = 0; i < tests ;++i){

       int x;
       vector<int> nums(7);
       
       for (int i = 0; i < 7; i++) {
        cin >> nums[i];
        }
       cout << max_sum(nums) << "\n";
    }
    
}

int max_sum(vector<int> nums){

    sort(nums.begin(), nums.end(), greater<int>());
    size_t size = nums.size();
    int sum = nums[0];

    // skip biggest 
    for (int i = 1; i < size; ++i) {
        
        nums[i] *= -1;

        sum += nums[i];
    }

    return sum;
}
