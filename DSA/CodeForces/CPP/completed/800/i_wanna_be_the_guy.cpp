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

    int n;
    cin >> n;
    
    vector<int> r(n);
    int l1;
    cin >> l1;

    for (int i = 0; i < l1; ++i) {
    
        int tmp;
        cin >> tmp;
        if(tmp == 0) {
            r[tmp]++;
        }else {
            r[tmp - 1]++;
        }
    }

    int l2;
    cin >> l2;
    for (int i = 0; i < l2; ++i) {
    
        int tmp;
        cin >> tmp;
        if(tmp == 0) {
            r[tmp]++;
        }else {
            r[tmp - 1]++;
        }
    }

    int f = 1;
    for (int i : r) {
        if(i == 0) f = 0;
    }
    f == 0 ? cout << "Oh, my keyboard!" : cout << "I become the guy.";
    cout << '\n';
}
