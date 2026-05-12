// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
void b_year(string t);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string test;

    cin >> test;

    b_year(test);
}

void b_year(string t){


    int f = 0;
    char arr[10] = {0};
    while (f == 0) 
    {
        memset(arr, 0, sizeof(arr));

        int n = stoi(t);
        n++;
        t = to_string(n);
        

        for (int i = 0; i < 4; ++i) {
            
            int idx = t[i] - '0';
            arr[idx]++; 
        }
    
        int total = 0;
        for (int i : arr) {
            
            if(i >= 2) goto end; // jump to end
        }
       

        f = 1; // all diff
        cout << t << '\n';


        end:
        ;
    }
   
}

