// g++ -o test test.cpp && ./test

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

long long maximun_power(ifstream &file){

    string line;

    // other var
    long long n_monsters;
    long long otter_combat_pw;
    long long n_flip_flops;
        
    // getting other values, since they are in sequence we can use
    // this stream extraction operator (that basically skips n/ and spaces)
    // read the data from the stream (this case file) and put in the var
    // matching their type
    file >> n_monsters >> otter_combat_pw >> n_flip_flops;

    vector<long long> monsters;
    /* Create vec and sort monsters*/
    for (int i = 0; i < n_monsters; i++){
        long long monster_pw;
        file >> monster_pw;

        monsters.push_back(monster_pw);
    }
    sort(monsters.begin(), monsters.end());

    // monsters power line
    for (int i = 0; i < n_monsters; i++) {
        
        // if otter can beat monster
        if(otter_combat_pw >= monsters[i]){

            // we want to be greedy and get the most of the monster

            // this will get us the used flip flops for this monster
            // because the n of flipflops we will use has to  be <
            // then the difference in pw and <= n of flipflops we have,
            // so choose min 
            long long flip_flop_used = min(otter_combat_pw - monsters[i], n_flip_flops);

            monsters[i] +=  flip_flop_used;
            n_flip_flops -= flip_flop_used;

            otter_combat_pw += monsters[i];
        }
    }
    return otter_combat_pw;

}

int main(){

    ifstream file("codeforces/2209/input.txt");

    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        return 0;
    }
    // test cases count
    int test_cases;
    file >> test_cases;


    for (int i = 0; i < test_cases; ++i) {
        printf("%lld\n", maximun_power(file));   
    }  
    
}