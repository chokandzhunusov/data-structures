/*
    Two method of implementing, depends on situation:
        1. Limited set of priorities
        2. Element priority
*/


struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};


void create(struct Queue *q, size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(size * sizeof(int));
}

void display(struct Queue q)
{
    for (int i=q.front+1; i<=q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}


void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size-1)
        printf("Queue is FULL");
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
        printf("Queue is EMPTY");
    else
    {
        x = q->Q[q.front];
        q->front++;
    }
    return x;
}


int main()
{
    struct Queue q1;
    struct Queue q2;
    struct Queue q3;
}