// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <unordered_map>

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

    unordered_map<string, int> team;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        string t;
        cin >> t;

        team[t]++;
    }

    int max = 0;
    for (const auto& [key, value] : team) 
    {
        if (value > max) max = value;
    }
    cout << max << '\n';

}
