/*
 *  ========================================
 *  Implementaion of Stack Using Linked List
 *  ========================================
 */


#include <stdio.h>
#include <stdlib.h>



struct Node
{
    int data;
    struct Node *next;
}*top=NULL;


void display()
{
    struct Node *p;
    p = top;
    while (p)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}


void push(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (!t)
        printf("Stack is Overflow \n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}


int pop()
{
    int r = -1;
    struct Node *t;
    if (!top)
        printf("Stack is Underflow\n");
    else
    {
        t = top;
        top = top->next;
        r = t->data;
        free(t);
    }
    return r;
}


int main()
{
    push(9);
    push(19);
    push(29);
    display();
    printf("%d \n", pop());
    display();
    return -1;
}
