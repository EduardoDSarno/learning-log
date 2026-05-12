// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <functional>
#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

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
    int sum = 0;

    vector<int> coins;

    for(int i = 0; i < n; ++i){
        int temp;
        cin >> temp;

        sum += temp;
        coins.push_back(temp);
    }

    // sort desceding 
    sort(coins.begin(), coins.end(), greater<int>()); 
    // for (int c  : coins) {
    //     printf("%d ", c);
    // }

    int count = 0;
    int sum2 = 0;
    double g = sum / 2.0;

    while (sum2 <= g) {
        sum2 += coins[count];
        count++;
    }

    cout << count << '\n';
}
