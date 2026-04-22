// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>


using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string word;

    cin >> word;
    size_t size = word.size();
    int flag = 1;
    // identify first letter does not metter
    for (int i = 1 ; i < size; ++i) {
        
        if(!isupper(word[i])){
            flag = 0;
            break;
        }
    }

    if(flag == 1){

        for (char &c : word) {
            
            (isupper(c)) ? c =  tolower(c) : c =  toupper(c);
        }
    }
    cout << word << '\n';
}
