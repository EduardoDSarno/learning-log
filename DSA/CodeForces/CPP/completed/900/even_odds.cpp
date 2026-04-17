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

    ll size, ith;

    cin >> size;
    cin >> ith;

    
    ll odds_num = (size + 1) / 2;

    ll f = 0;

    if(odds_num >= ith){

        // means f is odd
        f = (2 * ith) - 1;
    }
    else {    
        // f is even
        f = (ith - odds_num) * 2;
    }

    cout << f << '\n';

}
