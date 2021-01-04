/*
 * Static variable: creates once in code section of memory
 */


#include <stdio.h>


// Function that each time creates/allocates memory for `n`(line 9)
int func(int n)
{
    if (n > 0)
    {
        return func(n - 1) + n;
    }
    return 0;
}


// Function that will allocate memory for `x` just once, in code section
int func2(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return func2(n - 1) + x;
    }
    return 0;
}


int main()
{

}