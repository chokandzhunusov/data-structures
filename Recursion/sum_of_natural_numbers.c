/*
 *  ======================
 *  Recursion
 *  ======================
 *
 *  Finding Sum of First n Natural Numbers using recursion.
 *
 *  For recursive functions we have to define two type of statements:
 *      - for the large value of n
 *      - for the small value of n
 *
 *  Formula:
 *      - n(n+1)/2
 */


#include <stdio.h>


//  Time: O(n); Space: O(n), because of internally usage of stack.
int sum_of_natural_nums_recursion(int n)
{
    if(n==0)
        return 0;
    else
        return sum_of_natural_nums_recursion(n-1)+n;
}


//  Time: O(n); Space: O(1), allocate memory just for n, i, s.
int sum_of_natural_nums_loop(int n)
{
    int i, s=0;
    for(i=1; i<=n; i++)
        s = s + i;
    return s;
}

int main()
{

}