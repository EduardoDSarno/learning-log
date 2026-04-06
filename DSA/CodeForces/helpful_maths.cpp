// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;
void helpfull_maths(string line);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string line;

    cin >> line;
    
    helpfull_maths(line);

}

void helpfull_maths(string line){

    size_t lenght = line.size();
    int nums_size = lenght / 2 + 1; // just count the ints 

    vector<int> nums(nums_size);


    int count = 0;
    for (int i = 0; i < lenght; ++i) {
        
        if (line[i] != '+') 
        {
            nums[count] = line[i] - 48;
            count++;
        }
    }


    sort(nums.begin(), nums.end());

    cout << nums[0];
    for (int i = 1; i < nums_size; ++i)
    {
        cout << '+' << nums[i];
        
    }
    cout << "\n";

}

