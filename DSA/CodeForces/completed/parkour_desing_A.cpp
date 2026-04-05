// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <algorithm>


using namespace std;

void parkour_desing(long long x, long long  y);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // code
    int tests;

    cin >> tests;

    // read first line
    for(int i = 0; i < tests ;++i){

       long long x,y;

       cin >> x >> y;

       parkour_desing(x, y);
    }

    
}

void parkour_desing(long long x, long long  y){

    
    // int my_x = // a x move1[0] + b x move2[0] + c x move3[0]
    // // so my_x == 2a + 3b + 4c
    
    // int my_y = // a x move1[1] + b x move2[1] + c x move3[1]
    // // my_y = a  + 0 - c  ~= a = y + c  
    // // where my_x == x && my_y = y;

    if((x - 2*y) % 3 == 0 && x >= max(2*y, -4*y)){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }


    // substitue
    // x = 2y + 3b + 6c

        
}