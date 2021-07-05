/*
 *  ===========================
 *  Remove Duplications from LL
 *  ===========================
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


void deleteDuplicationsFromLL(struct Node *p)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t = p->next;

    while(t)
    {
        if (p->data != t->data)
        {
            p = t;
            t = t->next;
        }
        else
        {
            p->next = t->next;
            free(t);
            t = p->next;
        }
    }
}


int main()
{
    int A[] = {10, 20, 20, 20, 30, 40, 40, 50};
    create(A, 8);

    display(first);
    printf("\n\n");

    deleteDuplicationsFromLL(first);
    display(first);

    return 0;
}
