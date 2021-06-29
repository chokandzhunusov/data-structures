/*
 *  =====================================
 *  Recursive Display of Linked List
 *  =====================================
 */


#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[], int n)
{
    struct Node *last, *t;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void recursiveDisplayOfLL(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d, ", p->data);
        recursiveDisplayOfLL(p->next);
    }
}


void backwardRecursiveDisplayOfLL(struct Node *p)
{
    if (p != NULL)
    {
        backwardRecursiveDisplayOfLL(p->next);
        printf("%d, ", p->data);
    }
}


int main()
{
    struct Node *p;
    int A[] = {2, 5, 6, 9, 8};
    create(A, 5);
    backwardRecursiveDisplayOfLL(first);
    return 0;
}
