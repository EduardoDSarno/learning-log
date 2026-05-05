/*Two elements of a binary search tree have been swapped by mistake. Give
an O(n) algorithm to identify these two elements so they can be swapped back*/
#include <cstddef>
#include <cstdio>
#include <stdio.h>
#include <vector>
using namespace std;

typedef struct Node 
{
    int value;
    struct Node* left;
    struct Node* right;
}Node;


// this function will get a head for a bst and a vector and return a vectored with the bst sorted
// doing in order treversal
void in_order(Node * head, vector<int> &in_order_arr)
{
    // if bottom left is bigger the head
    if (head != NULL){

        in_order(head->left, in_order_arr);// left
        // visit
        in_order_arr.push_back(head->value);

        // go right
        in_order(head->right, in_order_arr);
    }

}

void find_wrong_nums(vector<int> in_order_arr)
{

    size_t size = in_order_arr.size();
    int first = -1;
    int second = -1;

    for (int i = 1; i < size ;++i)
    {

        if(in_order_arr[i - 1] > in_order_arr[i])
        {
            if (first == -1)
            {
                first = in_order_arr[i - 1];
                second = in_order_arr[i];
            }
            else 
            {
                second = in_order_arr[i];
            }
            
        }
    }
    int result[] = {first, second};

    for (int i : result)
     
    {
        printf("%d ", i);
    }
}

int main(void){

}
