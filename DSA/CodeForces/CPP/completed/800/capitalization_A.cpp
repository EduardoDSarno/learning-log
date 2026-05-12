// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cctype>
#include <cstdio>
#include <cstring>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

void capi(string s);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string s;

    cin >> s;

    // read first line
    capi(s);
}

void capi(string s){

    int i = 0;
    while (!isalpha(s[i])) 
    {
        i++;
    }
    s[i] = toupper(s[i]);
    cout << s << '\n';
    
}

