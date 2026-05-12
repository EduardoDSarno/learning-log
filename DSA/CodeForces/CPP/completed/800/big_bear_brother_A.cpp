// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>


using namespace std;
void cal_years(int a, int b);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int a,b;

    cin >> a;
    cin >> b;


    // read first line
    cal_years(a, b);

}


void cal_years(int a, int b){

    int count = 0;

    while (a <= b) {
    
        a *=3;
        b *=2;
        count++;
    }

    cout << count << '\n';

}
