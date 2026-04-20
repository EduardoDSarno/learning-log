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
    int n;

    cin >> n;

    int bills[] = {100, 20, 10, 5 ,1};
    int count = 0;
    
    for (int bill : bills) {
        
        while (n >= bill) 
        {
            n -= bill;
            count++;
            
        }
    }
    cout << count << '\n';
}
