
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int maximun_power(ifstream &file){

    string line;
    
    // test cases count
    int test_cases;
    file >> test_cases;

    // other var
    int n_monsters;
    int otter_combat_pw;
    int n_flip_flops;


    for (int i = 0; i < test_cases; ++i) {
        
        // getting other values, since they are in sequence we can use
        // this stream extraction operator (that basically skips n/ and spaces)
        // read the data from the stream (this case file) and put in the var
        // matching their type
        file >> n_monsters >> otter_combat_pw >> n_flip_flops;

        // monsters power line
        for (int i = 0; i < n_monsters; i++) {
            int monster_pw;
            file >> monster_pw;

            // if otter can beat monster
            if(otter_combat_pw > monster_pw){

                // we want to be greedy and get the most of the monster
                while (otter_combat_pw > monster_pw && n_flip_flops > 0) {
                    
                    // use flipflop
                    monster_pw++;
                    n_flip_flops--;
                }

                otter_combat_pw += monster_pw;
            }
        }
    }
    printf("%d n/", otter_combat_pw);
    return otter_combat_pw;

}

int main(){

    ifstream file("input.txt");

    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        return 0;
    }
    else 
    {
        maximun_power(file);
    }
}