/*
 *  ======================
 *  Recursion
 *  ======================
 *
 *  Combination Formula a.k.a. Selection Formula:
 *        nCr = n! / r!(n-r)!
 *        where r can take values from 0 to n
 *
 *      - If set of objects is given.
 *        Then how many ways we can select the subset of those objects.
 *
 *      - Given a set of objects: A, B, C, D, E, F, G
 *        Subset of above objects of length 3 may be:
 *        A, B, C
 *        A, B, D
 *        A, C, B  Not valid. Interchanging of positions will not give a new selection,
 *                 it's called: Permutation
 */


#include <stdio.h>

//  Time: O(n)
int factorial(n)
{
    if(n == 0 || n == 1) return 1;

    else return n * factorial(n-1);
}


//  Time: O(n)
int combination(n, r)
{
    int f1, f2, f3;
    f1 = factorial(n);      // n
    f2 = factorial(r);      // n
    f3 = factorial(n-r);    // n
    return f1/(f2*f3);
}


// Follows Pascal's Triangle
int recursive_combination(n, r)
{
    if(r==0 || r==n) return 1;
    else return recursive_combination(n-1, r-1) + recursive_combination(n-1, r);
}

int main()
{
    return 0;
}