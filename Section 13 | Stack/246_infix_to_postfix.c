#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
    char data;
    struct Node *next;
}*top=NULL;


void push(char x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if (t==NULL)
        printf("Stack is full");
    else
    {
        t->data = x;
        t->next=top;
        top=t;
    }
}


char pop()
{
    struct Node *t;
    char x = -1;

    if (top==NULL)
        printf("Stack is empty");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}


void display()
{
    struct Node *p;
    p = top;
    while (p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int isOperand(char x)
{
    if (x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    return 1;
}

int precedence(char x)
{
    if (x=='+' || x=='-')
        return 1;
    else if (x=='*' || x=='/')
        return 2;
    return 0;
}

char * convert(char *infix)
{
    int i=0, j=0;
    int len = strlen(infix)+2; // +1 is for `\0` and +1 is for hash '#'
    char *postfix;
    postfix = (char *)malloc(sizeof(char)*len);

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }

    while (top!=NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';

    return postfix;
}


int main()
{
    char *infix="a+b*c-d/e";
    push('#');
    char *postfix = convert(infix);
    printf("%s ", postfix);
    return 0;
}

