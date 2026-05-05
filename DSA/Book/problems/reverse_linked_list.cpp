// Skiena Book question 3-3 Exercise 3-10

#include <cstddef>
#include <cstdio>
struct Node
{
    char val;
    Node * next;
};

Node * reverse_linked_list(Node * start)
{

    Node * current = start;
    Node * prev = NULL;

    while (current != NULL) 
    {
        // just to save next next
        Node* next = current->next;
        
        printf("DEBUG: current = %p, current->val = %c\n", (void*)current, current ? current->val : '?');
        printf("DEBUG: prev = %p, prev->val = %c\n", (void*)prev, prev ? prev->val : '?');
        printf("DEBUG: next = %p, next->val = %c\n", (void*)next, next ? next->val : '?');

        // flip
        current->next = prev;
        // advance priv
        prev = current;
        //advance current copy
        current = next;
        puts(" ");
    }

    // return priv since current will be NULL 
    return prev;
}

int main(void){

    Node D = {'d', NULL};
    Node C = {'c', &D};
    Node B = {'b', &C};
    Node A = {'a', &B};
   
    
   Node *reversed = reverse_linked_list(&A);

   printf("%c\n\n", reversed->val);

   Node *reversed2 = reverse_linked_list(reversed);

   printf("%c\n\n", reversed2->val);
   

}