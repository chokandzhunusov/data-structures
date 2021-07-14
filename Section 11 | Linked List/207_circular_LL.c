/*
 *  =================================
 *  Circular Linked List
 *  =================================
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


int main()
{
    int A[] = {10, 20, 30, 40, 50, 10, 20, 30, 40, 50};
    create(A, 10);
    displayRecur(Head);

    return 0;
}
