/*
 *  =====================================
 *  About Linked List
 *  =====================================
 *  1. What is Linked List
        - Collection of nodes, which contains `data` and `pointer` to next node
        - First is a just a pointer, pointing to first NODE and it is called as: HEAD/FIRST
 *  2. What is Node
        - NODE => [data, next]
 *  3. Node Structure
        - It uses Self-Referential Structure
 *  4. Create a Node
        - using `struct`, it is `class` in C++
          diff is in `class` by default everything is private,
          whereas in `struct` everything is public
        - In compiler if data takes 2 bytes, then pointer will take also 2 bytes
 *  5. Access a Node
 */


#include <stdio.h>
#include <stdlib.h>


// Self-Referential structure
struct Node
{
    int data;
    struct Node *next;
}


int main()
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node)) // malloc returns void, so have to typecast
    p->data = 10;
    p->next = 0;    // means null, nothing stored there


    struct *w, *q;
    // assume w is pointing to some node already,
    q = w;  // means q will pointing to the same node as w
    q = w->next;
    w = w->next;  // moving pointer to next node


    // Defining a pointer which is not pointing to any Node: if (!z)
    // if (z==0)
    struct Node *z = 0;
    // if (z==NULL)
    struct Node *z = NULL;

    return 0;
}
