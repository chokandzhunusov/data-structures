/*
 * Parameters:
 *              Pass by Value
 *              Pass by Address
 *              Pass by Reference(c++)
 */


#include <stdio.h>


void swapByValue(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}


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
}


int main()
{
    int a, b;
    a = 10;
    b = 20;
    // eg of passing params by value == Pass by Value
    swapByValue(a, b);
    printf("%d %d", a, b);

    // eg of passing params by address == Pass by Address
    swapByAddress(&a, &b);
    printf("\n%d %d", a, b);
}