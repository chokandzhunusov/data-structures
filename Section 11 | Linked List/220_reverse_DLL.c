/*
 *  ===================================
 *  Reverse Doubly Linked List
 *  ===================================
 *  1. Display
 *  2. Reverse
 */


#include <stdio.h>
#include <stdlib.h>


struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[], int n)
{
    struct Node *last, *t;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = first->next = NULL;
    first->data = A[0];
    last = first;

    for (int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}


int length(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}


void display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


void reverse(struct Node *f)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    while (f)
    {
        temp = f->next;
        f->next = f->prev;
        f->prev = temp;
        f = f->prev;
        if (f && !f->next)
            first = f;
    }
}


int main()
{
    int A[] = {10, 20, 30, 40, 50, 10, 20, 30, 40, 50};
    create(A, 10);
    reverse(first);
    display(first);

    return 0;
}
