/*
 *  =====================================
 *  Addition of Sparse Matrix
 *  =====================================
 */


#include <stdio.h>
#include <stdlib.h>


struct Element
{
    int i;
    int j;
    int x;
};


struct Sparse
{
    // First index of compressed sparse row
    int m;      // i=0, num of rows
    int n;      // j=0, num of columns
    int num;    // x=total num of !0 elements
    // !0 elements that has to be created dynamically
    struct Element *e;
};


struct Sparse * Add(struct Sparse S1, struct Sparse S2)
{
    int i, j, k;
    i=j=k=0;
    struct Sparse *Sum;
    Sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    Sum->e =(struct Element *)malloc((S1.num+S2.num)*sizeof(struct Element));


    while (i<S1.num && j <S2.num)
    {
        if (S1.e[i].i < S2.e[j].i)
            Sum->e[k++] = S1.e[i++];
        else if (S1.e[i].i > S2.e[j].i)
            Sum->e[k++] = S2.e[j++];
        else
        {
            if (S1.e[i].j < S2.e[j].j)
                Sum->e[k++] = S1.e[i++];
            else if (S1.e[i].j > S2.e[j].j)
                Sum->e[k++] = S2.e[j++];
            else
            {
                Sum->e[k] = S1.e[i];
                Sum->e[k++].x = S1.e[i++].x + S2.e[j++].x;
            }
        }
    }

    for (; i<S1.num; i++)
        Sum->e[k++] = S1.e[i];

    for (; j<S2.num; j++)
        Sum->e[k++] = S2.e[j];

    Sum->m = S1.m;
    Sum->n = S1.n;
    Sum->num = k;

    return Sum;
}



void Create(struct Sparse *S)
{
    /*
    Order of insertion of elements matters: row by row
    */
    int i;
    printf("Please enter dimensions: ");
    scanf("%d %d", &S->m, &S->n);
    printf("Please enter num of non zero elements: ");
    scanf("%d", &S->num);

    S->e =(struct Element *)malloc(S->num*sizeof(struct Element));
    printf("Please enter all elements: ");
    for (i=0; i<S->num; i++)
    {
        scanf("%d%d%d", &S->e[i].i, &S->e[i].j, &S->e[i].x);
    }
    printf("\n");

}

void Display(struct Sparse S)
{
    int i, j, k=0;
    for(i=0; i<S.m; i++)
    {
        for(j=0; j<S.n; j++)
        {
            if(i==S.e[k].i && j==S.e[k].j)
                printf("%d ", S.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}


int main()
{
    struct Sparse S1, S2, *S3;

    Create(&S1);
    Create(&S2);

    S3 = Add(S1, S2);

    printf("First Matrix\n");
    Display(S1);

    printf("Second Matrix\n");
    Display(S2);

    printf("Sum Matrix\n");
    Display(*S3);

    return 0;
}