// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <unordered_set>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code

    unordered_set<int> shoes;

    for (int i = 0 ; i < 4; ++i){

        int temp;
        cin >> temp;
        if (shoes.count(temp) == 0)// not found
        {
            shoes.insert(temp);
        }
    }

    cout << 4 - shoes.size() << '\n';

}
