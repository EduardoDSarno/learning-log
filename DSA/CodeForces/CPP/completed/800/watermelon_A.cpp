// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>

#include <iostream>

using namespace std;

void watermelon(int x);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int test;

    cin >> test;
    watermelon(test);

    // read first line
    // for(int i = 0; i < tests ;++i){

       
    // }

    
}

void watermelon(int x){

    if (x <= 2) {
        cout << "NO";
        return;
    }
    (x % 2 == 0 && x > 2) ? cout << "YES" : cout << "NO";
}