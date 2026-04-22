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
    int k,l,m,n,d;
    cin >> k >> l >> m >> n >> d;

    int count = 0;

    for (int i = 1; i <= d; ++i) {
        
        if(i % k != 0 && i % l != 0 && i % m != 0 && i % n != 0){
            count++;
        }
    }
    int result = d - count;
    cout << result << '\n';
}
