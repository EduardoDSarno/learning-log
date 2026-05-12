// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>

using namespace std;
int fit_domino(int m, int n);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int m,n;

    cin >> m >> n;

    cout << fit_domino(m, n);
    cout << "\n";
    
}

int fit_domino(int m, int n){

    return (m * n) / 2;
}

