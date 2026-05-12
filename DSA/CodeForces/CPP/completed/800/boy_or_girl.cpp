// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <string>


using namespace std;

void boy_or_girl(string username);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string test;
    cin >> test;
    // read first line
    
    boy_or_girl(test);
    
}



void boy_or_girl(string username){
    
    unordered_set<char> unique_chars;
    int count = 0;

    for (char c : username) {
            
        auto ch = unique_chars.find(c);
        if(ch == unique_chars.end()){
            unique_chars.insert(c);
            count++;
        }

    }
    
    count % 2 == 0 ? cout << "CHAT WITH HER!" : cout << "IGNORE HIM!";
    cout << "\n";
}