// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int n,ith;

    cin >> n;
    cin >> ith;

    string queue;
    cin >> queue;

    // first check if it will go out of bounds
    
    for(int i = 0; i < ith; ++i){

        // if there is a girls behind a boy swap them
        for (int j = 0; j < n; j++) 
        {
            if(queue[j] == 'B' && queue[j + 1] == 'G'){

                queue[j]     = 'G';
                queue[j + 1] = 'B';
                j++;
            }
        }

    }

    cout << queue << '\n';
}