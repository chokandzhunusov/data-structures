/*
 *  =======================
 *  Tri-diagonal Matrix
 *  Square Band Matrix
 *  =======================
 *
 *
 *  1   2   0   0   0
 *  2   1   2   0   0
 *  0   2   1   2   0    <=  Tri-dioganal Matrix: have just on lower and one upper diagonal
 *  0   0   2   1   2
 *  0   0   0   2   1
 *                      M = 5x5
 *                      Main dioganal: i-j = 0
 *                      Upper diagonal: i-j = -1
 *                      Lower diagonal: i-j = 1
 *                      =========================
 *                                    : |i-j| <= 1

 *                      M[i,j]=0 if |i-j| > 1
 *                      M[i,j]=!0 if |i-j| <= 1

 *                      Num of `Non zero` elements = n + (n-1) + (n-1)
 *                                                 = 3n-2
 *
 *                      Index(A[i][j]):
 *                          CASE 1:  if i-j=1 => index=i-2
 *                          CASE 2:  if i-j=0 => index=n-1 + i-1
 *                          CASE 2:  if i-j=-1 => index=2n-1 + i-1
 *
 *  1   2   3   0   0
 *  2   1   2   3   0
 *  3   2   1   2   3   <=  Square Band Matrix: have more than one lower and more than one upper diagonal
 *  0   3   2   1   2
 *  0   0   3   2   1
 */


#include <stdio.h>
#include <stdlib.h>


struct Matrix
{
    int *A;
    int n;
};


void SetTriDiagonalMatrix(struct Matrix *m, int i, int j, int x)
{
    if (i-j == 1)
        m->A[i-2] = x;
    else if (i-j == 0)
        m->A[m->n-1 + i-1] = x;
    else if (i-j == -1)
        m->A[2*m->n-1 + i-1] = x;
}





void DisplayTriDiagonalMatrix(struct Matrix m)
{
    for(int i=1; i<=m.n; i++)
    {
        for(int j=1; j<=m.n; j++)
        {
            if (i-j == 1)
                printf("%d ", m.A[i-2]);
            else if (i-j == 0)
            {
                printf("%d ", m.A[m.n-1 + i-1]);
            }
            else if (i-j == -1)
                printf("%d ", m.A[2*m.n-1 + i-1]);
            else
                printf("%d ", 0);
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
    m.A = (int *)malloc((3*m.n-2) * sizeof(int));

    printf("Please enter all elements: ");
    for(int i=1; i<=m.n; i++)
    {
        for(int j=1; j<=m.n; j++)
        {
            scanf("%d", &x);
            SetTriDiagonalMatrix(&m, i, j, x);
        }
    }

    printf("\n\n");

    DisplayTriDiagonalMatrix(m);

    return 0;
}