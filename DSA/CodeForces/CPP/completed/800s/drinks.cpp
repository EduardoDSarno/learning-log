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
    double juices;

    cin >> juices;

    long double ml;
    long double all_ml = 0.0;

    for (int i = 0; i < juices; ++i) {
        
        cin >> ml;
        all_ml +=ml;
    }

    cout << (all_ml / juices) << '\n';
    
}
