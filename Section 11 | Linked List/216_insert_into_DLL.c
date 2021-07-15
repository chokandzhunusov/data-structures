/*
 *  ===================================
 *  Inserting Doubly Linked List
 *  ===================================
 *  1. Before first node
 *  2. at any given index
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


void insert(struct Node *f, int index, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    if (index == 0)
    {
        temp->prev = NULL;
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    else
    {
        for (int i=0; i<index-1; i++)
            f = f->next;
        temp->next = f->next;
        temp->prev = f;
        if (f->next)
            temp->next->prev = temp;
        f->next = temp;
    }
}


int main()
{
    int A[] = {10, 20, 30, 40, 50, 10, 20, 30, 40, 50};
    create(A, 10);
    display(first);
    insert(first, 10, 3);
    display(first);

    return 0;
}
