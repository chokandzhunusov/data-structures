/*
    - Insertion from right, Deletion from left.
    - 2 pointers(front, rear) used for time complexity optimization.
*/


#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
} *front=NULL, *rear=NULL; // Two pointers created/initialized globally


void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)  // Node is not created
        printf("Queue is FULL\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front=rear=t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}


int dequeue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
        printf("Queue is EMPTY\n");
    else
    {
        t = front;
        front = front->next;
        x = t->data;
        free(t);
    }
    return x;
}


void display()
{
    struct Node *p=front;
    if (!front)
        printf("The queue is EMPTY");
    else
    {
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}


int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    printf("%d \n", dequeue());

    display();

    return 0;
}
