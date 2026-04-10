// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

void trasnlate(string s1,string s2);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    string word1,word2;
    

    cin >> word1;
    cin >>word2;
    
    trasnlate(word1, word2);
}

void trasnlate(string s1,string s2){


    // not order safe
    // int sum1 = accumulate(s1.begin(), s1.end(), 0);
    // int sum2 = accumulate(s2.begin(), s2.end(), 0);
    

    size_t size1 = s1.size();
    size_t size2 = s2.size();

    if(size1 != size2) {
        cout << "NO";
        cout << '\n';
        return;
    }
    for (int i = 0; i < size1; i++){

        if(s1[i] != s2[size1 - i - 1]){
            cout << "NO"; 
            cout << '\n';
            return;
        }
    }
    cout << "YES";
    // sum1 == sum2 ? cout << "YES" : cout << "NO";
     cout << '\n';
}

