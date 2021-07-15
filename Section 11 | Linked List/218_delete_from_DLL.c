/*
 *  ===================================
 *  Deleting Node from Doubly Linked List
 *  ===================================
 *  1. Delete first node
 *  2. Delete Node at any given index
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


void delete(struct Node *f, int index)
{
    if (index < 1 || index > length(f))
        return;

    if (index == 1)
    {
        first = first->next;
        free(f);
        if (first)
            first->prev = NULL;
    }
    else
    {
        for (int i=0; i<index-1; i++)
            f = f->next;
        f->prev->next = f->next;
        if (f->next)
            f->next->prev = f->prev;
        free(f);
    }
}


int main()
{
    int A[] = {10, 20, 30, 40, 50, 10, 20, 30, 40, 50};
    create(A, 10);
    display(first);
    delete(first, 3);
    display(first);

    return 0;
}
