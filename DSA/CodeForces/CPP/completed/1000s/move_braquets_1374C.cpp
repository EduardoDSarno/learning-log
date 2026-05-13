// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <stack>


using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; t++) 
    {
        int nu;
        cin >> nu;
        
        stack<int> stck_m;
        stack<int> stck_bck;
        int c = 0;
        for (int i = 0; i < nu; i++) 
        {
            const char left_b = '(';
            char b;
            cin >> b;
            if(stck_m.empty())
            {
                if(b == left_b)
                {
                    stck_m.push(b);
                }
                else 
                {
                    stck_bck.push(b);
                    c++;
                }
            }
            else 
            {
                if(b == left_b)
                {
                    stck_m.push(b);
                }
                else 
                {
                    stck_m.pop();
                }

            }
        }
        cout << c<< '\n';
        c = 0;
    }

}