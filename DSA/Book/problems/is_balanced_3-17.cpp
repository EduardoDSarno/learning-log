#include <cstddef>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef struct Node 
{
    int value;
    struct Node* left;
    struct Node* right;
}Node;


int find_max_depth(Node * head)
{
    int left_height  = find_max_depth(head->left);
    int right_height = find_max_depth(head->right);

    if (left_height == -1 || right_height == -1)
    {
        return -1;
    }

    if(abs(left_height - right_height) > 1) return -1;

    return 1 + (max(find_max_depth(head->left), find_max_depth(head->right)));

}