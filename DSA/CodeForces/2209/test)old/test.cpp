// g++ -o test test.cpp && ./test

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/*SO the whole question was literally ignoring K completly because since 
    K can be any - or + number it will affect A-j and a_i results inversely 
    so just by fiding which of these have more elemenets as in, which side of 
    the line has more elements we find how much K needs to be without ever having to meniton
    */
vector<long>  array_b(vector<long> a){

    size_t size = a.size();


    vector<long> result(size, 0);

    for(int i = 0; i < size; ++i){
        
        if (size - i > 1) // so it does not got out of bounds
        {
            int a_j = 0;
            int a_i = 0;
            int k = 0;

            // J has to bigger then i
            for (int j = i + 1; j < size; ++j) // wathc for error here
            {
                /*Here I need to count Aj and Ai because we need to figure it out
                    which side of the imaginary line they will be*/
                if(a[j] > a[i])
                {
                    a_j++;
                }
                else if (a[j] == a[i]){
                    continue;
                }
                else {
                    a_i++;
                }
             
            }
            
            result[i] = max(a_i,a_j);


        } 
    }
    return result;
}

int main(void){
    vector<long> a = {105, -105};
    vector<long> result = array_b(a);

    for (int element : result) 
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}

