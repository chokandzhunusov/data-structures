/*
 *  =====================================
 *  Improve Searching in Linked List
 *  =====================================
 *  So, we can improve linear search and there are 2 methods
        1. Transposition: swap element with prev. one
            - Don't used bcs avoid movement of data in LL
        2. Move to header: move element to head
            - Move entire node to the beginning
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


void display(struct Node *p)
{
    while (p)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
}


struct Node * searchELemInLL(struct Node *p, int key)
{
    while (p)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}


struct Node * recursiveSearchELemInLL(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    return recursiveSearchELemInLL(p->next, key);
}

struct Node * improveSearchELemInLL(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}


int main()
{
    struct Node *node;
    int A[] = {2, 5, 6, 32, 8, 11};
    create(A, 6);

    node = improveSearchELemInLL(first, 8);
    node = improveSearchELemInLL(first, 6);

    if (node)
        printf("Matching was found: %d\n", node->data);
    else
        printf("Key was not found\n");

    display(first);

    return 0;
}
