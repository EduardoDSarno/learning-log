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
    int tests;

    cin >> tests;
    int in,out;

    // read first line
    int count = 0;
    int max = 0;
    for(int i = 0; i < tests ;++i){

       cin >> out;
       cin >> in;

        count = count - out + in;

        if(count > max) max = count;
    }
    cout << max << '\n';
    
}
