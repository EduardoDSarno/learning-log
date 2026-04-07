// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;

void string_task(string word);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string word;

    cin >> word;

    string_task(word);

}

void string_task(string word){

    // so we receive a string
    // we gotta delete first the vowels
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

    size_t size = word.size();
    string new_arr;

    for (int i = 0; i < size; ++i) {
        
        if (!vowels.count(tolower(word[i]))) { // if are consonats
            new_arr.push_back('.');
            new_arr.push_back(tolower(word[i]));
        }
    }
    cout << new_arr << '\n';
}
