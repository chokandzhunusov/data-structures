/*
 * Pointer:  Is address variable.
 *           That is meant for storing address of data.
 *           Not data itself.
 *           1. One reason of pointers is to access HEAP section of memory.
 *           2. Accessing resources outside of program.
 *           You may access external(out of program in `main`):
 *           monitor, keyboard, internet, hard disk with pointers.
 *           3. Parameter passing.
 */


#include <stdio.h>
#include <stdlib.h>


struct Rectangle
{
    int length;
    int breadth;
};


int main()
{
    int a = 10;     // data variable
    int *p;         // address variable(pointer)
    p = &a;         // initialization of pointer

    printf("\n var `a` accessed by Pointer is: %d", *p);     // *p => dereferencing

    // Static memory allocation in HEAP memory
    // allocating memory at HEAP
    int *t;
    t = (int *)malloc(5 * sizeof(int));

    // Pointer to Structure
    struct Rectangle r = {10, 5};
    struct Rectangle *z = &r;

    // Access of data in struct
    r.length = 22;

    // Member access of Struct using Pointer
    z -> length = 20;
    printf("\n `length` of Rectangle Struct accessed by Pointer is:  %d", z -> length);

    // Dynamic memory allocation in HEAP memory
    // Allocating memory for Pointer in HEAP that points to Struct
    struct Rectangle *x;
    x = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    x -> length = 10;
    x -> breadth = 5;
    printf("\n `length`, `breadth` data of Struct Rectangle memory allocated in HEAP is: %d, %d", x -> length, x -> breadth);
}