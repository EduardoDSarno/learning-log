// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <algorithm>


using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int a,b,c;
    cin >> a >> b >> c;

   // 1 3 2

   int add = a + b + c;
   int mult = a * b * c;

   int r = max(add,mult);
   int p = max((a + b) * c, a * (b + c));

   int re = max(p,r);
   cout << re << '\n';
}
    
