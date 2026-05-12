// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>

using namespace std;
void wrong_sub(int n, int k);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int n,k;

    cin >> n;
    cin >> k;
    wrong_sub(n, k);
}

void wrong_sub(int n, int k){

    for (int i = 0; i < k; ++i) {
        
        if(n % 10 == 0)
        {
            n /= 10;
        }
        else {
            n--;
        }
    }

    cout << n << '\n';
}

