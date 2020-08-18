/*
 *  ======================
 *  Recursion
 *  ======================
 *
 *  Taylor Series:
 *      - e^x = 1 + x/1 + x^2/2! + x^3/3! + ... + n terms.
 *        - Sum(n) = 1 + 2 + 3 + 4 + ... n              =>  Sum(n-1)+n
 *        - Factorial(n) = 1 * 2 * 3 * 4 * ... n.       =>  Fact(n-1)*n
 *        - Exponent(m, n) = m * m * ... * m [for n times].   =>  Exponent(m, n-1)*m
 *
 *
 */


#include <stdio.h>


double taylor_series(int x, int n)
{
    static double p=1, f=1;
    double r;
    if(n==0 || n<0)
        return 1;
    else
    {
        r = taylor_series(x, n-1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}


double taylor_series_horners_rule(int x, int n)
{
    static double s;
    if(n==0 || n<0)
        return s;
    s = 1 + x*s / n;
    return taylor_series_horners_rule(x, n-1);
}


double taylor_series_iterative(int x, int n)
{
    double s=1;
    int i;
    double num=1;
    double den=1;

    for(i=1; i<=n; i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}


int main()
{

}