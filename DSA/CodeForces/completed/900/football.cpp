// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
void is_degerous(string t);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string t;

    cin >> t;

    is_degerous(t);
}


void is_degerous(string t){

    

    int count = 1;
    char prev;
    for (char c : t) {
        c == prev ? count++ : count = 1;
        if(count >=7) break;
        prev = c;
    }

    count >= 7? cout << "YES" : cout << "NO";
    cout << '\n';
}
