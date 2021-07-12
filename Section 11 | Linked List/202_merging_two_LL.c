/*
 *  ================================
 *  Merging two Linked Lists
 *  ================================
 *  Theta(m+n)
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


void mergeLLs(struct Node *f, struct Node *s)
{
    struct Node *last=NULL;

    if (f->data < s->data)
    {
        third=last=f;
        f = f->next;
        third->next = NULL;
    }
    else
    {
        third=last=s;
        s = s->next;
        third ->next = NULL;
    }

    while(f && s)
    {
        if (f->data < s->data)
        {
            last->next = f;
            last = f;
            f = f->next;
            last->next = NULL;
        }
        else
        {
            last->next = s;
            last = s;
            s = s->next;
            last->next = NULL;
        }
    }

    if(f) last->next = f;
    if(s) last->next = s;
}


int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    int B[] = {1, 11, 22, 33, 37, 44, 55};
    createSecond(B, 7);

    printf("\n\n");

    mergeLLs(first, second);

    display(third);

    return 0;
}
