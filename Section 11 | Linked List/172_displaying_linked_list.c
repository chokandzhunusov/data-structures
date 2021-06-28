/*
 *  =====================================
 *  Display Linked List
 *  =====================================
 *  - Have to traverse(visit all elements once)
 *  - All operations can be done by traversing: add all elements, sort, count
 */


#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
}*first; // declaration of pointer globally


void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i=1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last=t;
    }
}


void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
}


int main()
{
    int A[] = {3, 5, 7, 10, 15};
    Create(A, 5);
    Display(first);
    return 0;
}
