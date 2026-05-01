/*3-11[3] Design a dictionary data structure in which search, insertion, and deletion
can all be processed in O(1) time in the worst case. You may assume the set
elements are integers drawn from a finite set 1,2,..,n, and initialization can take
O(n) time.*/



// Sincethe initiazlization can take O(n) they are say to us is a finite set from 1-n
// we can literally just use an array and map to n-1 to match index
// I will just create the functions because the questions asked but this should be bascially it
#include <vector>
using namespace std;

vector<int> create(int n);


#include <vector>
int main(void)
{

    int n = 10;

    vector<int> result = create(n);

}

vector<int> create(int n){

    vector<int> arr(n);

    return arr;
}

void insert(vector<int> arr, int num){

    arr[num + 1] = num;
}

void del(vector<int> arr, int num)
{
    arr[num + 1] = 0;
}

int searc(vector<int> arr, int num){

    return arr[num + 1];
}

