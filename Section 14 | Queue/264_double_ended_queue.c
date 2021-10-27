/*
    DoubleEndedQueue
    - Does not have to follow FIFO rule.
    - INPUT restricted DEQueue: front can not insert.
    - OUTPUT restricted DEQueue: rear can not delete.
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


void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(size * sizeof(int));
}


void insertFromFront(struct Queue *q, int x)
{
    if (q->front == -1)
        printf("Can not be inserted to FRONT anymore");
    else
    {
        q->Q[q->front] = x;
        q->front--;
    }
}


int deleteFromFront(struct Queue *q)
{
    int x = -1;
    if (q->front < q->rear)
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}


void insertFromRear(struct Queue *q, int x)
{
    if (q->rear < q->size)
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
    else
        printf("The queue is FULL");
}


int deleteFromRear(struct Queue *q)
{
    int x = -1;
    if (q->rear == q->front)
        printf("Queue is EMPTY");
    else
    {
        x = q->Q[q->rear];
        q->rear = q->rear-1;
    }

    return x;
}


void display(struct Queue q)
{
    if (q.rear == q.front)
        printf("The queue is EMPTY");
    else
    {
        int i = q.front + 1;
        while (i <= q.rear)
        {
            printf("%d ", q.Q[i]);
            i++;
        }
    }
    printf("\n");
}




int main()
{
    struct Queue q;
    create(&q, 3);
    insertFromRear(&q, 1);
    insertFromRear(&q, 5);
    insertFromRear(&q, 10);
    insertFromRear(&q, 15);
    display(q);
    deleteFromRear(&q);
    display(q);

    deleteFromFront(&q);
    deleteFromFront(&q);
    insertFromFront(&q, 9);

    display(q);
    return 0;
}