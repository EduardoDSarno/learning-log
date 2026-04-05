// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
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

int beatiful_matrix(int arr[5][5]);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code

    int array[5][5];

    // read first line
    for(int i = 0; i < 5 ;++i){

       for (int j = 0; j < 5; ++j) {
            cin >> array[i][j];
       }
    }

    cout << beatiful_matrix(array) << "\n";
}


int beatiful_matrix(int arr[5][5]){


    int curr_c = 0;
    int curr_r = 0;

    for(int i = 0; i < 5 ;++i){

        for (int j = 0; j < 5; ++j) {
            
            if (arr[i][j] == 1) {
                
                curr_r = i + 1;
                curr_c = j + 1;
            }
        }
     }

     // I want to get in the center [3][3]
     //printf("r: %d c: %d\n", curr_r, curr_c);
     int total = abs(curr_c - 3) + abs(3 - curr_r); // distance use abs
     return total;
}
