/*
 *  ============================
 *  Stack Using an Array
 *  ============================
 */


#include <stdio.h>
#include <stdlib.h>


struct Stack {
    int size;
    int top;
    int *S; // pointer to array items in Heap
};


void create(struct Stack *st)
{
    printf("ENter the size of Stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size*sizeof(int));
}


void display(struct Stack st)
{
    for (int i=st.top; i>=0; i--)
        printf("%d, ", st.S[i]);
    printf("\n");
}


int isEmpty(int top)
{
    return top==-1?1:0;
}


int isFull(int top, int size)
{
    return top==size-1?1:0;
}


void push(struct Stack *st, int x)
{
    if (st->top == st->size-1)
        printf("Stack Overflow");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}


int pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
        printf("Stack Undeflow");
    else
        x = st->S[st->top--];
    return x;
}


int peek(struct Stack st, int pos)
{
    int x = -1;
    if (st.top-pos+1<0)
        printf("Invalid position");
    else
        x = st.S[st.top-pos+1];
    return x;
}


int stackTop(struct Stack st)
{
    return st.S[st.top];
}


int main()
{
    struct Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    printf("%d \n", peek(st, 2));

    display(st);
    return 0;
}
