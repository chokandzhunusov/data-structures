/*
 *  =====================
 *  Is Linked List Sorted
 *  =====================
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


int isLLSorted(struct Node *p)
{
    int x = -65536;
    while(p)
    {
        if (p->data < x)
        {
            printf("Given LL is NOT sorted: \n");
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    printf("Given LL is sorted: \n");
    return 1;
}


int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    display(first);
    printf("\n\n");

    isLLSorted(first);
    display(first);

    return 0;
}
