/*Work out the details of supporting constant-time deletion from a singly
linked list as per the footnote from page 79, ideally to an actual implementation.
Support the other operations as eﬃciently as possible.*/

#include <stdlib.h>
typedef struct Node {

    int value;
    struct Node * next;

} Node;

void delete(Node * node){

    // lets say we have a -> b -> c

    // node is b
    // save a pointer to C so we can free later
    Node * ptr = node->next;

    // make B become a copy of C so now you have A->C->C
    node->value = node->next->value;
    node->next  = node->next->next; // skips over C jumping to eg: D

    free(ptr);

}