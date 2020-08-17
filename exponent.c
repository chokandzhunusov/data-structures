/*
 *  ======================
 *  Recursion
 *  ======================
 *
 *  Exponents using recursion.
 *
 *  m^n = m * m * m * m * m ... for n times.
 *
 *  pow(m, n) = m * m * m * m * m ... * n-1 times * m.
 *
 *  pow(m, n) = pow(m, n-1) * m
 *
 */


#include <stdio.h>


//  Time: O(n); Space: O(n), because of internally usage of stack.
int exponent_recursion(int m, int n)
{
    if(n==0 || n<0)
        return 1;
    return exponent_recursion(m, n-1) * m;
}


int exponent_recursion_faster_ver(int m, int n)
{
    if(n==0 || n<0)
        return 1;
    if(n%2==0)
        return exponent_recursion_faster_ver(m*m, n/2);
    return m * exponent_recursion_faster_ver(m*m, (n-1)/2);
}


//  Time: O(n); Space: O(1), allocate memory just for n, i, s.
int exponent_loop(int m, int n)
{
    int s = 1;
    for(int i=1; i<=n; i++)
        s = s * m;
    return s;
}

int main()
{

}