// [5] Describe how to modify any balanced tree data structure such that search,
// insert, delete, minimum, and maximum still take O(logn) time each, but suc-
// cessor and predecessor now take O(1) time each. Which operations have to be
// modified to support this?

#include <cstddef>
#include <cstdio>
#include <cstdlib>
typedef struct Node{

    Node * left_leaf;
    Node * right_leaf;
    int value;

} Node;

int main(void){

}

/*Function to insert new node in BST using recursion*/
Node * insert(Node * node, int value)
{
    
    if(node == nullptr)
    {
        node = new Node{NULL, NULL, value};
        return node;
    }
    else 
    {
        if(value < node->value)
        {
            node->left_leaf = insert(node->left_leaf, value);
        }    
        else 
        {
            node->right_leaf = insert(node->right_leaf, value);
        }
        return node;
    }
}

/*This function will remove a node from a tree*/
Node * remove(Node * node, int value)
{
    // base case
    if(node == NULL)
    {
        return NULL;
    }

    // Now we need to nagevate to find the Node to delete
    if(value < node->value)
    {
        // recursive to the left
        node->left_leaf = remove(node->left_leaf, value);
    }
    else if(value > node->value)
    {
        // recursion to the right
        node->right_leaf = remove(node->right_leaf, value);
    }
    else // this else will just be nodes found
    {
        // 0 children
        if(node->left_leaf == NULL && node->right_leaf == NULL)
        {
            delete node;
            return NULL;
        }
        // case where there's 1 children
        else if(node->left_leaf == NULL)
        {
            Node * temp = node->right_leaf;
            delete node;
            return temp;
        }
        else if(node->right_leaf == NULL)
        {
            Node * temp = node->left_leaf;
            delete node;
            return temp;
        }
        else  // Case where there're 2 children
        {
            // by convetion it seems the ideal is to delete the sucessor

            // successor
            Node * in_order_s = node->right_leaf;



            // go left so we don't break the tree by grabbing a bigger value then the precedecessor (left top)
            while (in_order_s->left_leaf != NULL) 
            {
                in_order_s = in_order_s->left_leaf;
            }
            // change value of removed node to in order
            node->value = in_order_s->value;
            node->right_leaf = remove(node->right_leaf, in_order_s->value);

        }

    }

    return node;
   
}