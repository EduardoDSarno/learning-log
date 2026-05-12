// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <stddef.h>
#include <vector>

using namespace std;

int passed_to_next_round(vector<int> constestants, int k);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int n,k;

    cin >> n;
    cin >> k;

    vector<int> contestants(n);

    // read first line
    for(int i = 0; i < n ;++i){

       cin >> contestants[i];
    }

    int result = passed_to_next_round(contestants, k);
    cout << result;
    cout << "\n";
    
}

int passed_to_next_round(vector<int> constestants, int k){

    size_t size = constestants.size();
    // printf("size: %lu\n",size);
    int break_even_Score = constestants[k - 1];
    int i = 0;

    while (i < size && constestants[i] >= break_even_Score && constestants[i] > 0) {
    
        i++;
    }

    return i;
}
