// Given two binary search trees, merge them into a doubly linked list in sorted order.
#include <cstddef>
#include <cstdio>
#include <vector>

using namespace std;

struct DoublyNode {
    int value;
    DoublyNode* prev;
    DoublyNode* next;
};

typedef struct Node 
{
    int value;
    struct Node* left;
    struct Node* right;
}Node;


void in_order_sort(Node * head, vector<int> &in_order_arr)
{
    // if bottom left is bigger the head
    if (head != NULL){

        in_order_sort(head->left, in_order_arr);// left
        // visit
        in_order_arr.push_back(head->value);

        // go right
        in_order_sort(head->right, in_order_arr);
    }
}

vector<int> merge(vector<int> vec1, vector<int> vec2)
{

    vector<int> final_vec;
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    size_t i = 0;
    size_t j = 0;
    while (i < size1 && j < size2) 
    {
        if(vec1[i] < vec2[j])
        {
            final_vec.push_back(vec1[i]);
            i++;
        }
        else 
        {
            final_vec.push_back(vec2[j]);
            j++;
        }
    }

    // adding rest if there is any from the left over array

    while (i < size1)
    {
        final_vec.push_back(vec1[i]);
        i++;
    }

    while (j < size2)
    {
        final_vec.push_back(vec2[j]);
        j++;
    }

    return final_vec;
}

int main(void){

    Node bst_one_1 = {1, NULL, NULL};
    Node bst_one_5 = {5, NULL, NULL};
    Node bst_one_3 = {3, &bst_one_1, &bst_one_5};

    Node bst_two_2 = {2, NULL, NULL};
    Node bst_two_6 = {6, NULL, NULL};
    Node bst_two_4 = {4, &bst_two_2, &bst_two_6};

    vector<int> bst_one_sorted;
    vector<int> bst_two_sorted;

    // creating 2 sorted arrays
    in_order_sort(&bst_one_3, bst_one_sorted);
    in_order_sort(&bst_two_4, bst_two_sorted);

    // mergning arrays into one sorted array
    vector<int> merged = merge(bst_one_sorted, bst_two_sorted);
    size_t merge_size = merged.size();

    DoublyNode * head = NULL;
    DoublyNode * prev_node = NULL;
    /* This loop will create a doublt linked list based on the array */
    for(size_t i = 0 ; i < merge_size; ++i)
    {
        DoublyNode *new_doubly = new DoublyNode();
        new_doubly->value = merged[i];
        new_doubly->next = NULL;

        if(i == 0) // first node
        {
            head = new_doubly; // setting head
            new_doubly->prev = NULL;
        }
        else 
        {
            prev_node->next = new_doubly;
            new_doubly->prev = prev_node;
        }
        prev_node = new_doubly;
    }

    // priting for testing
    printf("Forward: ");
    DoublyNode *current = head;
    DoublyNode *tail = NULL;
    while (current != NULL)
    {
        printf("%d ", current->value);
        tail = current;
        current = current->next;
    }
    printf("\n");

    printf("Backward: ");
    current = tail;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->prev;
    }
    printf("\n");

    return 0;
}

