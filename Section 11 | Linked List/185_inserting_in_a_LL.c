/*
 *  =====================================
 *  Inserting in a Linked List
 *  =====================================
 *  Cases:
        1. Inserting before first node
        2. Inserting after given position
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


void insertInLinkedList(struct Node *p, int index, int x)
{
    int i;
    struct Node *t;

    if (index < 0 || index > count(p))
        return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else if (index > 0)
    {
        p = first;
        for (i=0; i<index-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}


int main()
{
    int A[] = {2, 5, 6, 32, 8, 11};
    create(A, 6);

    insertInLinkedList(first, 8, 10);
    display(first);

    return 0;
}
