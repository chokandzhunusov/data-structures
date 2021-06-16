/*
 *  ===============
 *  Addition of Sparse Matrix
 *  ===============
 *
 *  - Dimensions must be same
 *                                      first index of arrays is dimension and num of !0 elem
 *  0   0   0   6   0   0       A  =>  [5, 1, 2, 3, 3, 5]    row
 *  0   7   0   0   0   0              [6, 4, 2, 2, 4, 1]    column
 *  0   2   0   5   0   0              [5, 6, 7, 2, 5, 4]    element
 *  0   0   0   0   0   0
 *  4   0   0   0   0   0
 *
 *  0   0   0   0   0   0       B  =>  [5, 2, 2, 3, 3, 4, 5]    row
 *  0   3   0   0   5   0              [6, 2, 5, 3, 6, 4, 1]    column
 *  0   0   2   0   0   7              [6, 3, 5, 2, 7, 9, 8]    element
 *  0   0   0   9   0   0
 *  8   0   0   0   0   0
 *
 *  0    0    0   6   0   0
 *  0    10   0   0   5   0
 *  0    2    2   5   0   7     A+B=C  => [5, 1,  2, 2, 3, 3, 3, 3, 4, 5]
 *  0    0    0   9   0   0               [6, 4,  2, 5, 2, 3, 4, 6, 4, 1]
 *  12   0    0   0   0   0               [   6, 10, 5, 2, 2, 5, 7, 9, 12]
 *
 */


#include <stdio.h>
#include <stdlib.h>


struct Matrix
{
    int *A;
    int n;
};


int main()
{
    return 0;
}