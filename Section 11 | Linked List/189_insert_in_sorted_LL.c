/*
 *  =============================================
 *  Inserting Last Node in a Linked List in O(1)
 *  =============================================
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


void insertInSortedLL(struct Node *p, int x)
{
    struct Node *t, *q=NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    // Case where No nodes there
    if(!first)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        // Element is smallest case
        if (p==first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}


int main()
{
    int A[] = {10, 20, 30, 40};
    create(A, 4);

    display(first);
    printf("\n\n");

    insertInSortedLL(first, 5);
    insertInSortedLL(first, 35) ;
    display(first);

    return 0;
}
