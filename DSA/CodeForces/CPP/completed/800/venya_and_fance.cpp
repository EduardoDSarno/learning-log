// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
void w(vector<int> ph, int p, int h);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code
    int people, height;

    cin >> people;
    cin >> height;

    vector<int> people_heights(people);

    for (int i = 0; i < people; ++i) {
        
        cin >> people_heights[i];
    }

    w(people_heights, people, height);
}

void w(vector<int> ph, int p, int h){


    int w = 0;
    for (int p : ph) {
        if(p > h) 
        {
            w += 2;
        }
        else {
            w++;
        }
    }

    cout << w << '\n';
}



