// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ostream>
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

    int n, q;
    vector<int> x;

    cin >> n;
    
    for (int i = 0; i < n; ++i) 
    {
        int a;
        cin >> a;
        x.push_back(a);
    }

    cin >> q;

    sort(x.begin(), x.end());
    for (int i = 0; i < q; ++i) 
    {
        int count = 0;
        int y;
        cin >> y;
        while (y > x[count]) 
        {
            count++;
        }
        cout << count <<'\n';
    }
}
