/*
 *  =======================
 *  Upper Triangular Matrix
 *  =======================
 *
 *  1   1   1   1   1
 *  0   1   1   1   1
 *  0   0   1   1   1
 *  0   0   0   1   1
 *  0   0   0   0   1
 *                      M = 5x5
 *                      M[i,j]=0 if i>j
 *                      M[i,j]=!0 if i<=j
 *                      Num of `Non zero` elements = 1+2+3+4+...+n
 *                                                 = n(n+1)/2
 *                                                 = n^2
 *                      Num of `Zero` elements     = n^2 - n(n+1)/2
 *                                                 = n(n-1)/2
 *
 *  - Row Major Formula
 *      Accessing Non-Zero elements: Index(A[i][j]) = [n+(n-1)+(n-2)+...+n-(i-2)] + (j-i)
 *                                                  = [n(i-1) - [1+2+3+...+i-2]] + (j-i)
 *                                                  = [n(i-1) - ((i-2)(i-1))/2] + (j-i)
 *
 *  - Column Major Formula
 *      Accessing Non-Zero elements: Index(A[i][j]) = j(j-1)/2 + i-1
 *
 */


#include <stdio.h>
#include <stdlib.h>


struct Matrix
{
    int *A;
    int n;
};


void SetRowMajorMatrix(struct Matrix *m, int i, int j, int x)
{
    if (i<=j)
        m->A[j*(j-1)/2 + (i-1)] = x;
}


int GetRowMajorMatrix(struct Matrix m, int i, int j)
{
    if (i>=j)
        return m.A[j*(j-1)/2 + (i-1)];
    else
        return 0;
}


void DisplayRowMajorMatrix(struct Matrix m)
{
    for(int i=1; i<=m.n; i++)
    {
        for(int j=1; j<=m.n; j++)
        {
            if(i>=j)
                printf("%d ", m.A[j*(j-1)/2 + (i-1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}


void SetColumnMajorMatrix(struct Matrix *m, int i, int j, int x)
{
    if (i<=j)
        m->A[m->n*(i-1)-((i-2)*(i-1))/2 + (j-i)] = x;
}


int GetColumnMajorMatrix(struct Matrix m, int i, int j)
{
    if (i>=j)
        return m.A[m.n*(i-1)-((i-2)*(i-1))/2 + (j-i)];
    else
        return 0;
}


void DisplayColumnMajorMatrix(struct Matrix m)
{
    for(int i=1; i<=m.n; i++)
    {
        for(int j=1; j<=m.n; j++)
        {
            if(i>=j)
                printf("%d ", m.A[m.n*(i-1)-((i-2)*(i-1))/2 + (j-i)]);
            else
                printf("0 ");
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
            SetColumnMajorMatrix(&m, i, j, x);
        }
    }

    printf("\n\n");

    DisplayRowMajorMatrix(m);
//    DisplayColumnMajorMatrix(m);

    return 0;
}