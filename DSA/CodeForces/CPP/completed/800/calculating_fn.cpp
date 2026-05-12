// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
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
    ll n,sum;

    cin >> n;

    if(n % 2 == 0){
        sum = n / 2;
    }
    else {
        sum = (ceil(n + 1) / 2) * -1;
    }
    cout << sum << '\n';
}
