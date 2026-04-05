// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>


using namespace std;

void maximize_medians_permutation(int n);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int tests;

    cin >> tests;

    // read first line
    for(int i = 0; i < tests ;++i){

        int x;
        cin >> x;
        maximize_medians_permutation(x);

    }

    
}

void maximize_medians_permutation(int n){

    // I have to construct a permunation 3n
    int lenght = 3 * n;
    vector<int> result;

    int x = n + 1;
    int y = 1;
    
    for(int i = 0; i < n;++i)
    {
        
        result.push_back(y);
        result.push_back(x);
        result.push_back(x + 1);
        
        y++;
        x += 2;

    }

    for (int i = 0; i < lenght; i++) 
    {
       cout << result[i] << " ";
        
    }
    cout << "\n";
}