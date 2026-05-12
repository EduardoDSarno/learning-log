// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int n;
    cin >> n;

    int freq[5]= {0};

    for (int i = 0; i < n; ++i) 
    {
        int c;
        cin >> c;
        freq[c]++;
    }
    
    int count = 0;
    

    // case groups 
    //4 
    count+= freq[4];

    // 3
    count += freq[3];
    freq[1] -= min(freq[1], freq[3]); // clean up of ones 

    // 2
    count += freq[2] / 2;

    // 1
    count += ceil(freq[1]/ 4); // remainins
}
