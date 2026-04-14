// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int tests;
    cin >> tests;

    int n,prev; 
    int cnt = 0;
    for (int i = 0 ; i < tests; ++i) {
        
        cin >> n;

        if(prev != n) cnt++;
        
        prev = n;
    }
    cout << cnt << '\n';
}
