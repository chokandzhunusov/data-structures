/*
 *  =====================================
 *  Searching in Linked List
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


int main()
{
    struct Node *p;
    int A[] = {2, 5, 6, 32, 8, 11};
    create(A, 6);
    struct Node *node = recursiveSearchELemInLL(first, 11);
    printf("Matching was found: %d", node->data);
    return 0;
}
