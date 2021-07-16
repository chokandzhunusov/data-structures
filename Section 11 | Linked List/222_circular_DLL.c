/*
 *  ===================================
 *  Circular Doubly Linked List
 *  ===================================
 */


#include <stdio.h>
#include <stdlib.h>


struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[], int n)
{
    struct Node *last, *t;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = first->next = NULL;
    first->data = A[0];
    last = first;

    for (int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
    last->next = first;
    first->prev = last;
}


int length(struct Node *p)
{
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != first);
    return count;
}


void displayCDLL(struct Node *f)
{
    do
    {
        printf("%d, ", f->data);
        f = f->next;
    } while (f != first);
}


void insertInCDLL(struct Node *f, int index, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;

    if (index < 0 || index > length(f))
        return;

    if (index == 0)
    {
        temp->next = f;
        temp->prev = f->prev;
        f->prev->next = temp;
        f->prev = temp;
        first = temp;
    }
    else
    {
        for (int i=0; i<index-1; i++)
            f = f->next;
        temp->next = f->next;
        temp->prev = f;
        f->next = temp;
        temp->next->prev = temp;
    }
}


void deleteNodeFromCDLL(struct Node *f, int index)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    if (index < 1 || index > length(f))
        return;

    if (index == 1)
    {
        f->prev->next = f->next;
        f->next->prev = f->prev;
        first = f->next;
        free(f);
    }
    else
    {
        for (int i=0; i<index-2; i++)
            f = f->next;
        temp = f->next;
        f->next = temp->next;
        temp->next->prev = f;
        free(temp);
    }
}


int main()
{
    int A[] = {10, 20, 30, 40, 50, 10, 20, 30, 40, 50};
    create(A, 10);
    deleteNodeFromCDLL(first, 10);
    displayCDLL(first);

    return 0;
}
