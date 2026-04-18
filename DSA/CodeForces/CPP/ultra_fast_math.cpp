// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string a,b;

    cin >> a >> b;

    string r;
    size_t len = a.size();
    for (int i = 0; i < len;++i) {

        cout << (a[i] ^ b[i]);
    }
    cout << '\n';
}
