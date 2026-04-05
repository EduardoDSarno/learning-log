#include <cstdio>
#include <iostream>

using namespace std;


int lawn_mower(long long  number_of_boards, long long  width_of_mower);

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
    for(int i = 0; i < tests ;++i){

       long long number_of_boards, width_of_mower;

       cin>>number_of_boards;
       cin>>width_of_mower;

       cout << lawn_mower(number_of_boards, width_of_mower) << "\n";
    }
    
}

int lawn_mower(long long number_of_boards, long long width_of_mower)
{

    // first grab the max removal that will be 
    long long  max_removal = width_of_mower - 1;

    long long  reminder = number_of_boards % width_of_mower;

    long long  result = 0;

    long number_of_groups = number_of_boards / width_of_mower;

    result = number_of_groups * max_removal;

    result += reminder;
    return result;

}



