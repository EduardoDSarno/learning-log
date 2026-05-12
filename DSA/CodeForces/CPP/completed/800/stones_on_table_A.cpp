// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>


using namespace std;
void stones_on_table(string stones, int lenght);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int legnht;
    string stones;

    cin >> legnht;
    cin >> stones;

    // read first line
    stones_on_table(stones, legnht);
    
}

void stones_on_table(string stones, int lenght){

    int count = 0;
    for (int i = 1; i < lenght; ++i) {
    
        if (stones[i] == stones[i - 1]) {
            count++;
        }
    }

    cout << count << "\n";
}