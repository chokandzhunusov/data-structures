/*
 *  ======================
 *  ROW/COLUMN major mapping/formula of nD arrays
 *  ======================
 *
 *  ROW major formula of 4D Array:
 *      LEFT -> RIGHT
 *      Type  A[d1][d2][d3][d4]
 *      Address(A[i1][i2][i3][i4]) = Lo + (i1 * d2 * d3 * d4 + i2 * d3 * d4 + i3 * d4 + i4) * w
 *                                 = n(n-1)/2 => O(n^2)
 *      HORNER'S RULE
 *      Optimizing by taking common = i4 + d4 * [i3 + d3 * [i2 + i1 * d2]]
 *                                  = n - 1 => O(n)
 *
 *  COLUMN major formula of 4D Array:
 *      * RIGHT -> LEFT
 *      Type  A[d1][d2][d3][d4]
 *      Address(A[i][j]) = Lo + (i4 * d1 * d2 * d3 + i3 * d1 * d2 + i2 * d1 + i1) * w
 *                         n(n-1)/2 => O(n^2)
 */


int main()
{
    return 0;
}