// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

void compare_strings(string one, string two);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string str1,str2;

    cin >> str1;
    cin >> str2;

    // read first line
    compare_strings(str1, str2);

    
}

void compare_strings(string one, string two){


    size_t size = one.size();
    int result = 0;

    for (int i =0 ; i < size; ++i) 
    {
        if      (tolower(one[i]) > tolower(two[i])){
            result = 1;
            break;
        }
        else if (tolower(one[i]) < tolower(two[i])) {
            result = -1;
            break;
        }
    }
    cout << result;
    cout << "\n";

}
