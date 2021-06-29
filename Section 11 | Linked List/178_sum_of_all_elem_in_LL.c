/*
 *  =====================================
 *  Sum of All Elements in Linked List
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


void sumOfElementsInLL(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    printf("The number of nodes in LL: %d", sum);
}


int recursiveSumOfElementsInLL(struct Node *p)
{
    if (p == NULL)
        return 0;
    return recursiveSumOfElementsInLL(p->next) + p->data;
}


int main()
{
    struct Node *p;
    int A[] = {2, 5, 6, 9, 8, 11};
    create(A, 6);
    int num_nodes = recursiveSumOfElementsInLL(first);
    printf("The number of nodes in LL: %d", num_nodes);
    return 0;
}
