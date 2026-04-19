// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <utility>
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

    int max = 0;
    int max_idx = 0;

    int min = 100;
    int min_idx = 0;

    for (int i = 0; i < n; ++i) {
        
        int t;
        cin >> t;
        if (t >= max) {
        
            max = t;
            max_idx = i;
        }
        if(t <= min){
            min = t;
            min_idx = i;
        }
    }

    int c = max_idx + (n - 1 - min_idx);
    if(min_idx < max_idx) c--; // swap happened

    cout << c << '\n';
    // if they overlapp
}