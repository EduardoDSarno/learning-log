// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
void count_winner(int games, string gamesplayed);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int tests;
    cin >> tests;
    string games;
    cin >> games;

    count_winner(tests, games);
}

void count_winner(int games, string gamesplayed){

    int count_d = 0;
    int count_a = 0;
    for (int i = 0 ;i < games; ++i){

        gamesplayed[i] == 'A' ? count_a++ : count_d++;
    }

    if (count_a > count_d) {
        cout << "Anton";
    }
    else if (count_d > count_a) {
        cout << "Danik";
    }
    else {
        cout << "Friendship";
    }

    cout << '\n';
}

