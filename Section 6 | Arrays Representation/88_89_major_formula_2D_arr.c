/*
 *  ======================
 *  ROW/COLUMN major mapping/formula of 2D arrays
 *  In C lang both are equally efficient in terms of time, bcs of same num of operations
 *  ======================
 *
 *  ROW major formula of 2D Array:
 *      LEFT -> RIGHT
 *      Address(A[i][j]) = Lo + (i * n + j) * w
 *          For any index that has to be accessed in memory where index starts at 0(zero)
 *          Where i=row index; j=column index; Lo=Location zero; n=num of columns; w=size of data type
 *      Address(A[i][j]) = Lo + ((i-1) * n + (j-1)) * w
 *          Not allowed in C lang. Num of operations is +1, so if array is too long it will cause slow program
 *          If index start from 1
 *
 *
 *  COLUMN major formula of 2D Array:
 *      * RIGHT -> LEFT
 *      Address(A[i][j]) = Lo + (j * m + i) * w
 *          For any index that has to be accessed in memory where index starts at 0(zero)
 *          Where i=row index; j=column index; Lo=Location zero; n=num of columns; w=size of data type
 *      Address(A[i][j]) = Lo + ((i-1) * n + (j-1)) * w
 *          Not allowed in C lang. Num of operations is +1, so if array is too long it will cause slow program
 *          If index start from 1
 */


int main()
{
    return 0;
}