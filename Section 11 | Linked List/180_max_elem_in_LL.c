/*
 *  =====================================
 *  Maximum Element in Linked List
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


void maxElementInLL(struct Node *p)
{
    int m = -32768;   // MIN_INT
    while (p)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    printf("The number of nodes in LL: %d", m);
}


int recursiveMaxElementInLL(struct Node *p)
{
    int x = 0;

    if (p == NULL)
        return INT32_MIN;

    x = recursiveMaxElementInLL(p->next);
    return x > p->data?x:p->data;
}


int main()
{
    struct Node *p;
    int A[] = {2, 5, 6, 32, 8, 11};
    create(A, 6);
    int max = recursiveMaxElementInLL(first);
    printf("The number of nodes in LL: %d", max);
    return 0;
}
