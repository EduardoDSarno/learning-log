// skiena question 3-4 book
/* Design a stack S that supports S.push(x), S.pop(), and S.findmin(), which
returnstheminimumelementof S. Alloperationsshouldruninconstanttime.*/

/* THe way I did for the min (since pop and puhs are simple) was to create a separate
    stack that tracks the min position */

#include <stddef.h>
#include <stdio.h>
#define MAX 10

void push(int * top, int  * stack, int *stack_min, int x)
{
    // write x to stack
    if(*top == MAX - 1)
    {
        printf("stack is full");
        return;
    }

    if(*top == 0)
    {
        stack_min[0] = x;
    }
    else 
    {
        stack_min[*top] = (x < stack_min[*top - 1]) ? x : stack_min[*top - 1];
    }
    stack[*top] = x;
    (*top)++;

    for (int i = 0; i < *top; ++i) 
    {
        printf("%d ",stack[i]);
    }
    puts("\nmin: ");
    for (int i = 0; i < *top; ++i) 
    {
        printf("%d ",stack_min[i]);
    }
    puts(" ");
}

void findMin(int *stack_min, int *top){

    printf("%d\n",stack_min[*top]);
}

void pop(int *top)
{
    (*top)--;
}

int main(void)
{

    int stack[MAX];
    int stack_min[MAX];
    int top = 0;   

    push(&top, stack, stack_min, 6);
    push(&top, stack, stack_min, 7);
    push(&top, stack, stack_min, 8);
    push(&top, stack, stack_min, 8);

    pop(&top);

    findMin(stack_min, &top);

}