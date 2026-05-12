// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <string>
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

    const string str1 = "I hate ";
    const string str2 = "I love ";
    const string str3 = "that ";
    const string str4 = "it";

    string final;
    for (int i = 1; i <= n; ++i) {
    
        if(i % 2 == 0) final += str2;
        if(i % 2 == 1) final += str1;
        
        if(i < n) final += str3;

        if(i == n) final += str4;
    }
    cout << final << '\n';
}
