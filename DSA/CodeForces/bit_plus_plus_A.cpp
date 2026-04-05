// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>


using namespace std;

int bit_plus_plus_operation(string operation, int &x);

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
    int x = 0;
    for(int i = 0; i < tests ;++i){

        string operation;
        cin >>operation;


        bit_plus_plus_operation(operation, x);
       
    }

    cout << x;
    cout << "\n";
}

int bit_plus_plus_operation(string operation, int &x){


    if (operation[1] == '+') {
        return x +=1;
    }

    if (operation[1] == '-') {
        return x -=1;
    }

    return x;
}