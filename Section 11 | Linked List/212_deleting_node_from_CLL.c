/*
 *  ===================================
 *  Deleting from Circular Linked List
 *  ===================================
 *  1. Deleting Head Node
 *  2. Deleting any other Node from given position
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


void delete(struct Node *p, int pos)
{
    if (pos < 0 || pos > length(Head))
        return;

    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (pos == 1)
    {
        while (p->next != Head)
            p = p->next;

        if (Head == p)
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        for (int i=0; i<pos-2; i++)
            p = p->next;
        t = p->next;
        p->next = t->next;
        free(t);
    }
}


int main()
{
    int A[] = {10, 20, 30, 40, 50, 10, 20, 30, 40, 50};
    create(A, 10);
    delete(Head, 13);
    displayRecur(Head);

    return 0;
}
