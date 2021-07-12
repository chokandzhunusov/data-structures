/*
 *  =================================
 *  Check is Linked Lists Making Loop
 *  =================================
 *  O(n)
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


int isLoop(struct Node *q, struct Node *p)
{
    while (p)
    {
        q = q->next;
        p = p->next;
        if (p)
            p = p->next;
        if (p == q)
        {
            printf("Loop detected in Linked List \n");
            printf("Occurance in:  %d and %d \n", q->data, p->data);
            return 1;
        }
        printf("%d and %d \n", q->data, p->data);
    }
    printf("Linked List is linear \n");
    return 0;
}


int main()
{
    int A[] = {10, 20, 30, 40, 50, 10, 20, 30, 40, 50};
    create(A, 10);

    struct Node *t1, *t2;

    t1 = first->next->next;
    t2 = first->next->next->next->next->next->next->next->next->next;
    t2->next = t1;

    printf("\n\n");

    printf("%d", isLoop(first, first));

    return 0;
}
