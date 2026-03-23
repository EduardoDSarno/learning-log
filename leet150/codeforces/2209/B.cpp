
#include <cstddef>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> array_t(vector<int> a, int k){

    size_t size =  a.size();

    vector<int> result;
    result.reserve(size);
    
    for(int i = 0; i < size; ++i){
        
        if (size - i > 1) // so it does not got out of bounds
        {
                // J has to bigger then i
            for (int j = i + 1; j < size; ++j) // wathc for error here
            {
                
                if (a[j] != a[i]) {
                    result[i]++;
                }
            }
        } 
    }
    return result;
}