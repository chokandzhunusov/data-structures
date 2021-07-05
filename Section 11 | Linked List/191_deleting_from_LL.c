/*
 *  =============================================
 *  Deleting from Linked List
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


int deleteFromLL(struct Node *p, int index)
{
    int i, x;
    struct Node *t=NULL;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (index < 1 || index > count(p))
        return -1;

    if (index == 1)
    {
        x = p->data;
        first = first->next;
        free(p);
    }
    else if(index > 0)
    {
        for (i=0; i<index-1; i++)
        {
            t = p;
            p = p->next;
        }
        x = p->data;
        t->next = p->next;
        free(p);
    }
    return x;
}


int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    display(first);
    printf("\n\n");

    deleteFromLL(first, 1);
    display(first);

    return 0;
}
