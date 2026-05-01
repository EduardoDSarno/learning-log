#include <stdio.h>
#include <stdlib.h>
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

/*
THis alghortim runs on O(n) or O(h)
 since it recursive step will be going down
 (moving left or right) on the tree
 the worst case scenario (time complexity)
 will be the ones mentioned above */
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

void *insert(Bst * parent, int key, Bst **leg)
{
    if (parent == NULL) return NULL;
    
    /* Checking if one of the legs is null (left or right)*/
    if(*leg == NULL){
        Bst *new = malloc(sizeof(Bst));

        new->left = NULL;
        new->right = NULL;
        new->parent = parent;
        new->key = key;

        *leg = new;
    }

    // go left
    if (parent->key > key) {
        insert(parent->left, key, leg);
    }

}
int main(void){
    return 0;
}