// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>

#include <iostream>
#include <ostream>

using namespace std;

int implemented_problems(int x, int y, int z);
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
    int result = 0;
    for(int i = 0; i < tests ;++i){

        int x,y,z;

        cin >> x >> y >> z;

        
        result += implemented_problems(x,y,z);
    }

    cout << result;
    cout << "\n";

}

int implemented_problems(int x, int y, int z){

    int sum = x + y + z;
    if (sum < 2) {
        return 0;
    }
    return 1;
}

