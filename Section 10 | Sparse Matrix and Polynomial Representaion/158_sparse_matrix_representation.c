/*
 *  ===============
 *  Sparse Matrix
 *  ===============
 *
 *  - Contains more number of 0(zero) elements
 *
 *
 *  0   0   0   0   0   0    0   3   0
 *  0   0   8   0   0   10   0   0   0
 *  0   0   0   0   0   0    0   0   0
 *  4   0   0   0   0   0    0   0   0
 *  0   0   0   0   0   0    0   0   0
 *  0   2   0   0   0   0    0   0   0
 *  0   0   6   0   0   0    0   0   0
 *  0   9   0   5   0   0    0   0   0
 *                                      M = 8x9
                                          = 72 elements
                                          = 72 * 2 bytes => 144 bytes
 *
 *  - METHODS TO STORE/REPRESENT:
 *      1. Coordinate List / 3-column representation
            ROW     COLUMN      ELEMENT
             8        9           8         First row is for dimension of matrix and num of !0 elements
             ======================
             1        8           3
             2        3           8
             2        6           10
             .        .           .
             .        .           .
             .        .           .

 *      2. Compressed Sparse Row representation
            A = [3, 8, 10, 4, 2, 6, 9, 5]       => !0 elements in matrix
            Every row will contain its own elements num + prev row

            IA = [0, 1, 3, 3, 4, 4, 5, 6, 8]    => accumulative number of elements for each row
                  0, 1, 2, 3, 4, 5, 6, 7, 8     => row index

            JA = [8, 3, 6, 1, 3, 4, 2, 5]
            ============================================================
            A = 8 elements
            IA = 9 elements
            JA = 8 elements
               = 25 * 2 bytes => 50 bytes
               = 60% of memory is reduced from original matrix

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