// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
using namespace std;

void banana_borrowing(int k, int n , int w);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int price,dollars , banana_num;

    cin >> price;
    cin >> dollars;
    cin >> banana_num;

    banana_borrowing(price, dollars, banana_num);
}

void banana_borrowing(int k, int n , int w){


    // first calcualte the price of bananas

    int price_b_total = 0;

    for (int i = 1; i <= w; ++i) {
        
        price_b_total += (k * i);
    }

    int dollars_toB = price_b_total - n;

    dollars_toB < 0 ? cout << 0 : cout << dollars_toB;
    cout << '\n';
}

