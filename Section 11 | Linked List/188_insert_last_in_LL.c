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


struct Node * insertAtLastInLL(struct Node *last, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (!first)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
    return last;
}


int main()
{
    int A[] = {8, 6, 3};
    create(A, 3);

    display(first);
    printf("\n\n");

    struct Node *last1, *last2, *last=first;
    while(last->next)
        last = last->next;

    last1 = insertAtLastInLL(last, 7);
    last2 = insertAtLastInLL(last1, 79);
    display(first);

    return 0;
}
