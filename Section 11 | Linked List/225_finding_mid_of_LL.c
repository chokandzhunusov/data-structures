/*
 *  ============================
 *  Finding a mid of Linked List
 *  ============================
 *  - Procedure that will be required in Binary Search
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


struct Node * findMidInNLogN(struct Node *p)
{
    int midIndex = count(p)/2;
    for (int i=0; i<midIndex; i++)
        p = p->next;

    return p;
}


struct Node * findMidInNUsingExtraPointer(struct Node *p)
{
    struct Node *t;
    midNode = (struct Node *)malloc(sizeof(struct Node));
    midNode = first;
    while (p)
    {
        p = p->next;
        if (p)  p = p->next;
        if (p)  midNode = t->next;
    }

    return midNode;
}


int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    create(A, 7);

    display(first);
    printf("\n\n");

    struct Node *midNode = findMidInNUsingExtraPointer(first);
    printf("%d, ", midNode->data);

    return 0;
}
