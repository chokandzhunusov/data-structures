/*
 *  ======================
 *  Recursion
 *  ======================
 *
 *  Towers Of Hanoi:
 *      1, 2, 2^2, 2^3, ..., 2^n = (2^n+1) - 1
 */


#include <stdio.h>


//  Time: O(2^n) Exponential time
void TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1, A, C, B);
        printf("from %d to %d \n", A, C);
        TOH(n-1, B, A, C);
    }
}


int main()
{
    TOH(1, 1, 2, 3);
    return 0;
}