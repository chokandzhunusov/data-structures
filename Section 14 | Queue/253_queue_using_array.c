/*
    1. Queue using - Single pointer:
        - Insertion takes O(1), whereas Deletion O(n)
    2. Queue using - Front and Rear
    3. Drawbacks of using Queue using Array
*/



#include <stdio.h>
#include <stdlib.h>


struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};


void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size-1)
        printf("The Queue is full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}


int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("The Queue is empty");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}


void create(struct Queue *q, int size)
{
    q->size = size;
    q->front=q->rear=-1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}


void display(struct Queue q)
{
    for(int i=q.front+1; i<=q.rear; i++)
        printf("%d, ", q.Q[i]);
    printf("\n");
}


int main()
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(q);
    printf("%d \n", dequeue(&q));
    display(q);

    return 0;
}