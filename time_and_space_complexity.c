/*
 * =============================
 * Time and space complexity
 * =============================
 *
 * - Number of elements in an array = n.
 *   Time taken to make some operation on that list depends,
 *   but at most it will take `n`(element not found) time.
 *   `n` should be represented as degree/order => O(n).
 */


// Assume that every `simple statement` takes one unit of time:
// assignment, condition, arithmetic operation.


#include <stdio.h>


// Example that takes f(n) = 3
// And degree is O(1), bcs we take degree of polynomial: 3n^0 = 1
void swap(int x, int y)
{
    int t;
    t = x;  // 1
    x = y;  // 1
    y = t;  // 1
}


// Example that takes f(n) = 2n + 3
// And degree is O(n)
int sum(int  A[], int n)
{
    int s, i;
    s = 0;                      // 1
    for(i=0; i<n; i++)          // n + 1
        s = s + A[i];           // n
    return s;                   // 1
}


// Example that takes f(n) = 2n^2 + 2n + 1
// And degree is O(n^2)
void add(int n)
{
    int C[2][3], i, j;
    int A[2][3] = {
        {1, 2, 3},
        {1, 2, 3},
    };
    int B[2][3] = {
        {1, 2, 3},
        {1, 2, 3},
    };

    for(i=0; i<2; i++)                          // n + 1
    {
        for(j=0; j<n; j++)                      // n * (n + 1)
        {
            C[i][j] = A[i][j] + B[i][j];         // n * n
        }
    }

    printf("\n\nTwo dimensional matrix addition values are: ");
    for(int k=0; k<2; k++)
    {
        for(int h=0; h<n; h++)
        {
            printf("\n%d", C[k][h]);
        }
    }
}


int main()
{
    int nums[5] = {1, 2, 3, 4, 5};
    int sum_result = sum(nums, 5);
    printf("The sum of numbers from 1 to 5 is: %d", sum_result);

    add(3);
}
