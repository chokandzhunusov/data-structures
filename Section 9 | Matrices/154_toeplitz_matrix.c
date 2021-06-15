/*
 *  ===============
 *  Toeplitz Matrix
 *  ===============
 *
 *
 *  1   2   3   4   5
 *  2   1   2   3   4
 *  6   2   1   2   3
 *  7   6   2   1   2
 *  8   7   6   2   1
 *
 *                      M = 5x5
 *                      M[i,j] = M[i-1, j-1]
 *                      Sufficient elements(to be stored) = n+(n-1)
 *                                                        = 1st row + (1st column-1)
 *
 *
 *                      Index(A[i][j]):
 *                          CASE 1:  if i<=j => Index = j-i
 *                                    belongs to row(in array), means upper triangular
 *                          CASE 2:  if i>j => Index = n+i-j-1
 *                                    belongs to column(in array), means lower triangular
 *
 */


#include <stdio.h>
#include <stdlib.h>


struct Matrix
{
    int *A;
    int n;
};


void SetElementInToeplitzMatrix(struct Matrix *m, int i, int j, int x)
{
    if (i<=j)
        m->A[j-i] = x;
    else  if(i>j)
        m->A[m->n+i-j-1] = x;
}


void DisplayToeplitzMatrix(struct Matrix m)
{
    for(int i=1; i<=m.n; i++)
    {
        for(int j=1; j<=m.n; j++)
        {
            if(i<=j)
                printf("%d ", m.A[j-i]);
            else  if(i>j)
                printf("%d ", m.A[m.n+i-j-1]);
        }
        printf("\n");
    }
}


int main()
{
    int x;
    struct Matrix m;
    printf("Please enter dimentions: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n + m.n - 1 * sizeof(int));

    printf("Please enter all elements: ");
    for(int i=1; i<=m.n; i++)
    {
        for(int j=1; j<=m.n; j++)
        {
            scanf("%d", &x);
            SetElementInToeplitzMatrix(&m, i, j, x);
        }
    }

    printf("\n\n");

    DisplayToeplitzMatrix(m);

    return 0;
}