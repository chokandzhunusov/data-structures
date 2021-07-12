/*
 *  ================================
 *  Concatenating a two Linked Lists
 *  ================================
 */


#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;


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


void createSecond(int A[], int n)
{
    struct Node *last, *t;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

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


void concatTwoLLs(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
}


int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);


    int B[] = {11, 22, 33, 44, 55};
    createSecond(B, 5);

    display(first);
    printf("\n\n");

    concatTwoLLs(first, second);

    display(third);

    return 0;
}
