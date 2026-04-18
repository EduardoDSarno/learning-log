// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>

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

    string word;
    cin >> word;

    size_t s = word.size();
    vector<int> freq(26);
    int f = 1; //flag
    if(s < 26) 
    {
        cout << "NO";
        goto end;
    }
    for (int i = 0; i < s; ++i) {
    
        int idx = tolower(word[i]) - 'a'; // 0-25
        freq[idx]++;
    }

    
    for (int i : freq) {
        if(i == 0) f = 0;
    }

    
    f == 0? cout << "NO" : cout << "YES";
    end:
        cout << '\n';
}
