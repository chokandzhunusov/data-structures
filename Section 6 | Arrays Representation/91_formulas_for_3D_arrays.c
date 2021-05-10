/*
 *  ======================
 *  ROW/COLUMN major mapping/formula of 3D arrays
 *  ======================
 *
 *  ROW major formula of 3D Array:
 *      LEFT -> RIGHT
 *      Type  A[l][m][n]
 *      Address(A[i][j][k]) = Lo + (i*m*n + j*n + k) * w
 *                                 = n(n-1)/2 => O(n^2)
 *
 *  COLUMN major formula of 3D Array:
 *      RIGHT -> LEFT
 *      Type  A[l][m][n]
 *      Address(A[k][j][k]) = Lo + (k*l*m + j*l + i) * w
 *                         n(n-1)/2 => O(n^2)
 */


int main()
{
    return 0;
}