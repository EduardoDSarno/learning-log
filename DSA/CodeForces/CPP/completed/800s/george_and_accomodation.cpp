// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int nrroms;
    cin >> nrroms;
    int count = 0;

    for (int i = 0; i < nrroms; ++i) {
        
        int p,q;

        cin >> p;
        cin >> q;

        if(q - p >= 2) count++;
    }
    cout << count << '\n';
}
