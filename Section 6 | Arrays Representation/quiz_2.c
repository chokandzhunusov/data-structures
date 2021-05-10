/*  Q1:
 *  Let a be a 2D array declared as:
 *      A: array[1...10][1...15] of integer
 *  Assuming that each integer takes one memory location. The array is stored
 *  in row-major order and the first element of the array is stored at location 100,
 *  what is the address of the elements A[i][j] ?
 *
 *  S1:
 *  Lo = 100 (start location, base)
 *  w = 1 (size of integer is 1 byte)
 *  Address(A[i][j]) = Lo + (i-1) * n + (j-1)
 *           [1...10][1...15]
 *              m   X   n
 */