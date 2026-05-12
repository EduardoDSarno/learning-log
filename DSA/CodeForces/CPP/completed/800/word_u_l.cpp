// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
void upper_or_lower_word(string word);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string word;

    cin >> word;

    upper_or_lower_word(word);
}

void upper_or_lower_word(string word){

    int av = ceil(word.size() / 2.0);
    int count_lower = 0;
    size_t size = word.size();
    
    for (int i = 0;i < size ; ++i) {
        
        if(islower(word[i])){
            count_lower++;
        }
    }
    for (int k = 0; k < size; ++k) {
        
        if (count_lower >= av) {
            word[k] = tolower(word[k]);
        }
        else {
            word[k] = toupper(word[k]);
        }
    }

    cout << word << '\n';
}

