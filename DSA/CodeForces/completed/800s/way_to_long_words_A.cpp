// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

void too_long_words(string word);
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

        string word;

        cin >> word;
        too_long_words(word);
       
    }

    
}

void too_long_words(string word){

    size_t size = word.size() - 2; // minus first and last letters
    size_t s    = word.size();

   
    if (s > 10) 
    {
        cout << word[0] << size << word[s - 1] ;
    }
    else 
    {
        cout << word;
    }
    
    cout << "\n";
}
