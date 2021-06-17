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
    struct Sparse *Sum;
    Sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    Sum->e =(struct Element *)malloc((S1.num+S2.num)*sizeof(struct Element));
    Sum->m = S1.m
    Sum->n = S1.n
}



void Create(struct Sparse *S)
{
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
    struct Sparse S1;
    struct Sparse S2;

    Create(&S1);
    Create(&S2);

    Display(S);
    return 0;
}