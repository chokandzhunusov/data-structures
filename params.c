/*
 * Parameters: Pass by Value, Pass by Address, Pass by Reference(c++)
 *             Passing `array` is only pass by addresses
 *             Passing `structure`
 */


#include <stdio.h>
#include <stdlib.h>


void swapByValue(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
};


void swapByAddress(int *x, int *y)
{
    /*
     * Indirectly accesses values of another function
     * using `pointers`. Can't access without them(pointers)
     */
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
};


void f(int A[], int n)
{
    /*
     * A: an array, passed by address
     * n: size of array, passed by value
     */
    int i;
    for (i=0; i<n; i++)
        printf("\n%d", A[i]);
};


int * f2(int n)
{
    /*
     * n: size of array to be allocated in HEAP memory
     */
     int *p;
     p = (int *)malloc(n*sizeof(int));
     return (p);
};


struct Rectangle
{
    int length;
    int breadth;
};


int area(struct Rectangle r1)
{
    /*
     * Separate object will be created fro r1 with values length, breadth
     */
     return r1.length * r1.breadth;
};


void changeLength(struct Rectangle *p, int l)
{
    /*
     * Change by address
     */
    p -> length = l;
};

struct containsArray
{
    int A[5];
    int n;
};


void structParamContainsArray(struct containsArray t)
{
    t.A[0] = 10;
    t.A[2] = 11;
};


int main()
{
    // eg of passing params by value == Pass by Value
    int a, b;
    a = 10;
    b = 20;
    swapByValue(a, b);
    printf("%d %d", a, b);


    // eg of passing params by address == Pass by Address
    swapByAddress(&a, &b);
    printf("\n%d %d", a, b);


    // eg of passing `arrays` to function
    int A[5] = {2, 3, 4, 5, 6};
    f(A, 5);


    // eg of returning an `array` in function
    int *B;
    B = f2(5);


    // eg of passing `structure` to function == Call by Value
    struct Rectangle r = {10, 5};
    printf("%d", area(r));

    // eg of passing `structure` to function == Call by Address
    changeLength(&r, 20);


    // eg of passing `structure` that contains array to function == Call by Address
    struct containsArray t = {{2, 4, 5, 6, 10}, 5};
    structParamContainsArray(t);
}