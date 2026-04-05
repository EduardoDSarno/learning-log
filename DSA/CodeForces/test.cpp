// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <stddef.h>
#include <vector>
#include <algorithm>


using namespace std;
void reverse_a_permutation(vector<int> &nums, int lenght);

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

        int lenght;
        cin >> lenght;

        vector<int> nums(lenght);

        for (int i = 0; i < lenght; i++) {
            cin >> nums[i];
        }
         reverse_a_permutation(nums, lenght);
          
    }
    return 0;
    
}

void reverse_a_permutation(vector<int> &nums, int lenght){

    // we have to find a way to check if there is any number to the right that is bigger then you, just ONCE
 
    // for example check for the first number index[0] see if there's any to the right or best the MAX number to the right,
    // if not move check the next index and so on
 
     
    // maybe is a sliding windown we go adding to the right until we find a bigger number or the end, if not we add left
    // I am forgetting one thing, the problem says that a permuation is all it's digits from 1-n, so if right is smaller then
    // n we know there is a bigger number
    int n = lenght;
    for (int i = 0; i < lenght; ++i) {
     
         // so we loop until we find the leftest number that has a bigger to the right
         if(nums[i] != n) // this means it is NOT the max of the array
                         // we want to leave the N's in order and they reduce by one when we walk
         {
            auto iter = max_element(nums.begin() + i, nums.end()); // returs a pointer to max
            //  index = iter - nums.begin();  since both return pointers, we subtract and get the offset which is the index
            reverse(nums.begin() + i, iter + 1); // + 1 to be inclusive
            break;
         }
         n--;
    }

    for (int i = 0; i < lenght; i++) 
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
 
 }