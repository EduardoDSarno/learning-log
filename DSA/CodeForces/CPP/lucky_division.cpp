// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
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
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    vector<int> lucktN = {4,7,44,47,74,77,444,447,474,
                        477,744,747,774,777};


    int t, f = 0;
    cin >> t;
    for (int i = 0; i < 14; i++) 
    {
        if(t % lucktN[i] == 0)
        {
              f = 1; 
              break;
        }
    }

    f == 1 ? cout << "YES" : cout << "NO";
    cout << '\n';
    
}
