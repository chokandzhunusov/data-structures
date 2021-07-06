/*
 *  =======================
 *  Reversing a Linked List
 *  =======================
 *  1. Reversing elements
 *  2. Reversing Links
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

int count(struct Node *p)
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
        printf("%d, ", p->data);
        p = p->next;
    }
}


void reversingLLByUsingElements(struct Node *p)
{

    int *A, i;
    A = (int *)malloc(sizeof(int)*count(p));
//    int sizeOfLL = count(p);
//    int A[sizeOfLL], i=0;

    while(p)
    {
        A[i++] = p->data;
        p = p->next;
    }
    p = first;
    i--;
    while(p)
    {
        p->data = A[i--];
        p = p->next;
    }
}


void reversingLLUsingSlidingPointers(struct Node *p)
{
    struct Node *r, *q;
    r=q=NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;

}


void recursiveReversingOfLL(struct Node *q, struct Node *p)
{
    if(p)
    {
        recursiveReversingOfLL(p, p->next);
        p->next = q;
    }
    else
        first = q;
}


int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    display(first);
    printf("\n\n");

    struct Node *q=NULL;
    recursiveReversingOfLL(q, first);

    display(first);

    return 0;
}
