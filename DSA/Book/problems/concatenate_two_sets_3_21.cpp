/*3-21. [8] A concatenate operation takes two sets S1 and S2, where every key in S1 is
smaller than any key in S2, and merges them. Give an algorithm to concatenate
two binary search trees into one binary search tree. The worst-case running
time should be O(h), where h is the maximal height of the two trees.*/
#include "modify_balenced_tree_ptr3_3_20.cpp"
#include <cstddef>
#include <regex>


Node * concatenate_two_sets(BST &t1, BST &t2)
{
    // Base cases
    if (t1.root == NULL) return t2.root;
    if (t2.root == NULL) return t1.root;

    Node * parent = NULL;
    Node * current = t1.root;

    while (current->right_leaf != NULL) 
    {
        parent = current;
        current = current->right_leaf;
    }

    if (parent != NULL) {
        parent->right_leaf = current->left_leaf;
        current->left_leaf = t1.root;
    } else {
        current->left_leaf = NULL;   // T1 had only this node
    }
    current->right_leaf = t2.root;

    return current;
}