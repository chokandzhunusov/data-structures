/*
 *  ================
 *  Symmetric Matrix
 *  ================
 *
 *  2   2   2   2   2
 *  2   3   3   3   3
 *  2   3   4   4   4
 *  2   3   4   5   5
 *  2   3   4   5   6
 *                      M = 5x5
 *                      If M[i,j] == M[j,i]
 *
 *  - Upper or Lower triangular approach for storing symmetric matrix are both applicable
 *      Index(A[i][j]) = [n+(n-1)+(n-2)+...+n-(i-2)] + (j-i)
 *                     = [n(i-1) - [1+2+3+...+i-2]] + (j-i)
 *                     = [n(i-1) - ((i-2)(i-1))/2] + (j-i)
 *
 *      Index(A[i][j]) = j(j-1)/2 + i-1
 *
 */


#include <stdio.h>
#include <stdlib.h>


struct Matrix
{
    int *A;
    int n;
};


void SetLowerTriangularRowMajorSymmetricMatrix(struct Matrix *m, int i, int j, int x)
{
    m->A[i*(i-1)/2 + j-1] = x;
}


void DisplayLowerTriangularRowMajorSymmetricMatrix(struct Matrix m)
{
    for(int i=1; i<=m.n; i++)
    {
        for(int j=1; j<=m.n; j++)
        {
            if (i<=j)
                printf("%d ", m.A[j*(j-1)/2 + i-1]);
            else
                printf("%d ", m.A[i*(i-1)/2 + j-1]);
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
    m.A = (int *)malloc(m.n*(m.n+1)/2 * sizeof(int));

    printf("Please enter all elements: ");
    for(int i=1; i<=m.n; i++)
    {
        for(int j=1; j<=m.n; j++)
        {
            scanf("%d", &x);
            SetLowerTriangularRowMajorSymmetricMatrix(&m, i, j, x);
        }
    }

    printf("\n\n");

    DisplayLowerTriangularRowMajorSymmetricMatrix(m);

    return 0;
}