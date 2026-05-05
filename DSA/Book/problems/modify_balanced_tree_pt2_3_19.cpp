/*3-19. [5] Suppose you have access to a balanced dictionary data structure that sup-
ports each of the operations search, insert, delete, minimum, maximum, suc-
cessor, and predecessor in O(logn) time. Explain how to modify the insert
and delete operations so they still take O(logn) but now minimum and max-
imum take O(1) time. (Hint: think in terms of using the abstract dictionary
operations, instead of mucking about with pointers and the like.)*/

#include "modify_balanced_tree3_18.cpp"
#include <cstddef>

typedef struct BST
{
    Node * root;
    int max_value;
    int min_value;
    bool empty_values; // to check 
} BST;

/* 
    Passing address insated of passing pointer make sure that caller
    just use a real value, a pointer can cause nullptr */
void insert_node_bst(BST &tree, int value)
{
    // insert the node
    tree.root = insert(tree.root, value, NULL, NULL);

    // check if there's a min or max established
    if(tree.empty_values)
    {
        tree.max_value = value;
        tree.max_value = value;
        tree.empty_values = false;
    }
    else 
    {
        // update maximum values
        if(tree.min_value > value) tree.min_value = value;
        if(tree.max_value < value) tree.max_value = value;
    }
}

int find_min_value_tree(Node * node)
{
    while (node->left_leaf != NULL) 
    {
        node = node->left_leaf;
    }
    return node->value;
}
int find_max_value_tree(Node * node)
{
    while(node->right_leaf != NULL)
    {
        node = node->right_leaf;
    }
    return node->value;
}

void remove_node_bst(BST & tree, int value)
{
    tree.root = remove(tree.root, value);

    // check if there's any values to delete
    if(tree.root == NULL)
    {
        tree.empty_values = true;
    }
    else 
    {
        // we just have to replace min or max when the value given is equal to it
        if(tree.min_value == value) tree.min_value = find_min_value_tree(tree.root);
        if(tree.max_value == value) tree.max_value = find_max_value_tree(tree.root);
    }
}