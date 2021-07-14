/*
 *  ===================================
 *  Inserting Into Circular Linked List
 *  ===================================
 *  1. Insert before Head
 *  2. Insert to any other position
 */


#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
}*Head=NULL;


void create(int A[], int n)
{
    struct Node *last, *t;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}


int length(struct Node *h)
{
    int count = 0;
    do
    {
        count++;
        h = h->next;
    } while (h != Head);
    return count;
}


void displayIter(struct Node *h)
{
    do
    {
        printf("%d, ", h->data);
        h = h->next;
    } while (h!=Head);
    printf("\n");
}


void displayRecur(struct Node *h)
{
    static int flag = 0;
    if (flag==0 || h!=Head)
    {
        flag = 1;
        printf("%d, ", h->data);
        displayRecur(h->next);
    }
    flag = 0;
}


void insert(struct Node *p, int pos, int x)
{
    if (pos < 0 || pos > length(Head))
        return;

    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (pos == 0)
    {
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        while (p->next != Head)
            p = p->next;
        t->next = Head;
        p->next = t;
        Head = t;
    }
    else
    {
        for (int i=0; i<pos-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}


int main()
{
    int A[] = {10, 20, 30, 40, 50, 10, 20, 30, 40, 50};
    create(A, 10);
    insert(Head, 0, 99);
    displayRecur(Head);

    return 0;
}
