// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>

using namespace std;
using ll = long long;
void nearly_lucky(ll n);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    ll lucky;

    cin >> lucky;

    nearly_lucky(lucky);
    
}


void nearly_lucky(ll n){

    int count = 0;
    while(n > 0){
        if(n % 10 == 7 || n % 10 == 4){
            count++;
        }

        n /= 10; // rip of last digit
    }

    (count == 4 || count == 7) ? cout << "YES" : cout << "NO";
    cout << '\n';
}
