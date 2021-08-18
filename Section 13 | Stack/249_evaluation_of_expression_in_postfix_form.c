#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
    int data;
    struct Node *next;
}*top=NULL;


void push(int x)
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


int pop()
{
    struct Node *t;
    int x = -1;

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
    if (x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
        return 0;
    return 1;
}


int outStackPrecedence(char x)
{
    if (x=='+' || x=='-')
        return 1;
    else if (x=='*' || x=='/')
        return 3;
    else if (x=='^') // right to left associative operator(decreasing)
        return 6;
    else if (x=='(')
        return 7;
    return 0;
}


int inStackPrecedence(char x)
{
    if (x=='+' || x=='-')
        return 2;
    else if (x=='*' || x=='/')
        return 4;
    else if (x=='^')  // right to left associative operator(decreasing)
        return 5;
    else if (x=='(')
        return 0;
    return 0;
}


// Converting expression that involves more operands and that have right to left association
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
            if (outStackPrecedence(infix[i]) > inStackPrecedence(top->data))
                push(infix[i++]);
            else if (outStackPrecedence(infix[i]) == inStackPrecedence(top->data))
            {
                pop();
                i++;
            }
            else
                postfix[j++] = pop();
        }
    }

    while (top!=NULL)
        postfix[j++] = pop();
    j--;  // To remove initially added '#' to stack which should not be empty for comparison
    postfix[j] = '\0';

    return postfix;
}


int evaluate(char *postfix)
{
    int i, x1, x2, r;
    for(i=0; postfix[i]!='\0'; i++)
    {
        if (isOperand(postfix[i]))
            push(postfix[i]-'0'); // -'0' is to get int from string, changing just type will not help
        else
        {
            x2 = pop();
            x1 = pop();
            switch(postfix[i])
            {
                case '+': r = x1 + x2; push(r); break;
                case '-': r = x1 - x2; push(r); break;
                case '*': r = x1 * x2; push(r); break;
                case '/': r = x1 / x2; push(r); break;
            }
        }
    }
    return top->data;
}


int main()
{
    char *infix="2+3*4-8/2";
    push('#');
    printf("\nGiven expression of `infix` form: %s \n", infix);
    char *postfix = convert(infix);
    printf("It's `postfix` form: %s \n", postfix);

    int result = evaluate(postfix);
    printf("Evaluated result is: %d \n", result);

    return 0;
}

