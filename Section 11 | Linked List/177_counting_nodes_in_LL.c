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


void countNodesOfLL(struct Node *p)
{
    int num_nodes = 0;
    while (p != NULL)
    {
        num_nodes++;
        p = p->next;
    }
    printf("The number of nodes in LL: %d", num_nodes);
}


int recursiveCountNodesOfLL(struct Node *p)
{
    if (p == NULL)
        return 0;
    return recursiveCountNodesOfLL(p->next) + 1;

}


int recursiveCountNodesOfLL_2(struct Node *p)
{
    int x = 0;
    if (p)
    {
        x = recursiveCountNodesOfLL_2(p->next);
        return x+1;
    }
    return x;
}


int main()
{
    struct Node *p;
    int A[] = {2, 5, 6, 9, 8, 11};
    create(A, 6);
    int num_nodes = recursiveCountNodesOfLL_2(first);
    printf("The number of nodes in LL: %d", num_nodes);
    return 0;
}
