/*
 *  ======================
 *  Recursion
 *  ======================
 *
 *  Finding a Factorial of a given n using recursion.
 *
 */


#include <stdio.h>


//  Time: O(n); Space: O(n), because of internally usage of stack.
int factorial_recursion(int n)
{
    if(n==0 || n<0)
        return 1;
    return factorial_recursion(n-1)*n;
}


//  Time: O(n); Space: O(1), allocate memory just for n, i, s.
int factorial_loop(int n)
{
    int i, s=1;
    for(i=1; i<=n; i++)
        s = s * i;
    return s;
}

int main()
{

}