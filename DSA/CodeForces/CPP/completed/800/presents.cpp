// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int f;
    cin >> f;
    vector<int> p(f);

    for (int i = 0; i < f; ++i) {
        
        int t;
        cin >> t;
        p[i] = t;
    }

    // here we have the vec full 
    vector<int> new_v(f);
    for (int i = 0; i < f; ++i) 
    {
        // the first vec i becomes next vec p[i]
        new_v[p[i] - 1] = i + 1;
    }
    for (int a : new_v) {
    
        printf("%d ", a);
    }
    cout << '\n';
   
}
