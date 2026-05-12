// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <unordered_set>
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
    string letters;
    char c;
    unordered_set<char> letter_s;
    int count = 0;
    int idx = 0;
    while(c != '}')
    {
        cin >> c;
        
        if(c >= 'a' && c <= 'z')
        {
            // element does not exits
            if(letter_s.count(c) == 0)
            {
                count++;
                letter_s.insert(c);
            }
        }
    
    }
    
    cout << count << '\n';
    return 0;
}
