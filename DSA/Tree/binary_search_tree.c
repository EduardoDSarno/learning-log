#include <stdio.h>
#include <string.h>

/*
this struct seeing in Skienna books,
considers that the BST itself is a node
for navegation it is perfect, since we 
don't need any metadata, we just isolate the triangle
(parent, left, right) and we recursivelly update it
for search as it will be show below*/

typedef struct Bst {
    int key; 
    struct Bst * parent;
    struct Bst * left;
    struct Bst * right;
     
} Bst;

Bst * search_tree(Bst *tree, int key){

    if (tree == NULL) {
        return NULL;
    }

    if (tree->key == key) {
        return tree;
    }

    // if key is smaller this means we go left
    if (key < tree->key) {
        printf("Going left");
        return search_tree(tree->left, key);
    }
    else {
        printf("Going right");
        return search_tree(tree->right, key);
    }
}

int main(void){
    return 0;
}