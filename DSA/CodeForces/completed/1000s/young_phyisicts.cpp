// g++ -std=c++17 -DLOCAL -o test test.cpp && ./test

/* Set up*/
#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;
void equilibrium(vector<vector<int>> body, int test_lines, int body_lenght);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    
    // code

    int tests_lines;
    int body_lenght = 3;

    cin >> tests_lines;
    vector<vector<int>> tests;

    // read first line
    for(int i = 0; i < tests_lines ;++i){

        vector<int > temp(body_lenght);
        for (int j = 0; j < body_lenght; ++j) {
            
            cin >> temp[j];
        }
        tests.push_back(temp);
       
    }

    equilibrium(tests, tests_lines, body_lenght);
    
}

void equilibrium(vector<vector<int>> body, int test_lines, int body_lenght)
{

    int flag = 0;
    // inverted order loop, collums - rows
    for(int i = 0; i < body_lenght ;++i){
        int sum = 0;
        for (int j = 0; j < test_lines; ++j) {
            sum += body[j][i];
        }
       if(sum != 0 ) flag = 1;
    }

    flag == 0? cout << "YES" : cout << "NO";
    cout << '\n';
}