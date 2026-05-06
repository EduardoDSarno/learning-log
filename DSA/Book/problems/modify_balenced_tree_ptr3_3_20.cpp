#include "modify_balanced_tree_pt2_3_19.cpp"


Node * delete_kth_node(Node * node, int kth)
{
    // base case
    if(node == NULL)
    {
        return NULL;
    }

    int l = size(node->left_leaf);

    if(kth <= l)
    {
        node->left_leaf =  delete_kth_node(node->left_leaf, kth);
    }
    else if(kth == l + 1)
    {
        node = remove(node, node->value);
    }
    else
    {
        node->right_leaf = delete_kth_node(node->right_leaf, kth - l - 1);
    }
    
    if (node != NULL) {
        node->subtree_size = 1 + size(node->left_leaf) + size(node->right_leaf);
    }
    return node;
}

