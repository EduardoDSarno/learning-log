// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>

using namespace std;
int maximazie_min(int x);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int tests;

    cin >> tests;

    // read first line
    for(int i = 0; i < tests ;++i){
        int x;
        cin >> x;
        cout << maximazie_min(x) << "\n";
    }

    
}

int maximazie_min(int x){

    // my goal here is to maxime the min(x,y), by given me X
    // we know the the mostobivous case is y is equal x+1;


    // so let's separate 
    int y = x + 1;

    if (x == 67 || x == -67) {
        y = x;
    }

    return y;
}
