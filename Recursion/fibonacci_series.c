/*
 *  ======================
 *  Recursion
 *  ======================
 *
 *  Fibonacci Series:
 *      - 1, 1, 2, 3, 5, 8, 13
 */


#include <stdio.h>


//  Time: O(n)
int fibonacci_iterative(int n)
{
    int t0=0, t1=1, s=0;

    if(n<=1) return n;

    for(int i=2; i<=n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}


//  Time: O(2^n)
//  Excessive recursion, because it knows answer for some values,
//  but calls anyway if you'll track using tree method
int fibonacci_recursion(int n)
{
    if(n<=1) return n;

    return fibonacci_recursion(n-2) + fibonacci_recursion(n-1);
}


//  Time: O(n).
//  Because of using Memoization.
//  Method of storing result of functions,
//  so that it can be utilized again.
int F[10];  // Don`t forget to initialize an array with -1

int fibonacci_recursion_memoization(int n)
{
    if(n<=1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=fibonacci_recursion_memoization(n-2);
        if(F[n-1]==-1)
            F[n-1]=fibonacci_recursion_memoization(n-1);
        F[n] = F[n-2] + F[n-1];
        return F[n-2] + F[n-1];
    }
    return 0;
}


int main()
{
    return 0;
}