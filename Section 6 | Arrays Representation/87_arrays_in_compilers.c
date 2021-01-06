/*
 *  ======================
 *  Array representation in Compiler
 *  ======================
 *   Address(A[i]) = Lo + i * w
 *      For any index that has to be accessed in memory where index starts at 0(zero)
 *      Where i=index; Lo=Location zero; w=size of data type
 *  Address(A[i]) = Lo + (i-1) * w
 *      Not allowed in C lang. Num of operations is +1, so if array is too long it will cause slow program
 *      If index start from 1
 */


int main()
{
    return 0;
}