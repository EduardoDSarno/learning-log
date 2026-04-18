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

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        
        int a,b;
        cin >> a >> b;

        int c = (a + (b - (a % b)));
        int r = 0;
        if (a % b != 0) r = c - a; 
        cout << r << '\n';
    }
}
