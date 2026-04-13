// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int tests;

    cin >> tests;
    int t;
    int result = 0;
    // read first line
    for(int i = 0; i < tests ;++i){

       cin >> t;

       if(t == 1) result = 1;
    }

    result == 1 ? cout << "HARD" : cout << "EASY";

    cout << '\n';
}

