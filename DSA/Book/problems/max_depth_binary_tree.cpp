#include <cstddef>
#include <algorithm>

using namespace std;

typedef struct Node 
{
    int value;
    struct Node* left;
    struct Node* right;
}Node;


// to find the max depth of a tree I am assuming we receving just the headh node
// so I beleive a good idea will be to remember last branch and until 2 legs of the brench have being seen
// and gogin max deeper possible
int find_max_depth(Node * head)
{

    if (head == NULL)
    {
        return 0;
    }
    return 1 + (max(find_max_depth(head->left), find_max_depth(head->right)));

}