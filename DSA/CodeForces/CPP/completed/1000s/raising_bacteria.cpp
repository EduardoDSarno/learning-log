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
    int x;
    cin >> x;
    int count = 0;
    
    while (x != 0) 
    {
        count += x % 2;
        x /= 2;
    }
    cout << count << '\n';
    
}
