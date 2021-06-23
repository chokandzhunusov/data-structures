/*
 *  =====================================
 *  Polynomial Representation
 *  =====================================
 *  1. Representation
 *  2. Evaluation
 *  3. Addition of two Polynomials
 *
 *  p(x) = 3x^5 + 2x^4 + 5x^2 + 2x + 7  => used for problem solving,
             [collection of terms]         but it's paper based representation
            |       |      |    |    |
           term1    t2     t3   t4   t5

           coefficient * variable ^ exponent
 */


#include <stdio.h>
#include <stdlib.h>


struct Term
{
    int coeff;  // coefficient
    int exp;    // exponent
};


struct Polynomial
{
    int n;  // number of terms
    struct Term *t;
};


void Create(struct Polynomial *P)
{
    printf("Please enter num of terms: ");
    scanf("%d", &P->n);
    P->t = (struct Term *)malloc(P->n * sizeof(struct Term));
    for (int i=0; i<P->n; i++)
    {
        printf("Enter coefficient and exponent for term: %d\n", i+1);
        scanf("%d%d", &P->t[i].coeff, &P->t[i].exp);
    }
}


int Evaluate(struct Polynomial P, int x)
{
    int i, sum=0;
    for (i=0; i<P.n; i++)
        sum += P.t[i].coeff * (x * P.t[i].exp);
    return sum;
}


void Display(struct Polynomial P)
{
    int i;
    for (i=0; i<P.n; i++)
        printf("%dx^%d + ", P.t[i].coeff, P.t[i].exp);
    printf("\n");
}


struct Polynomial * Add(struct Polynomial P1, struct Polynomial P2)
{
    int i, j, k;
    i=j=k=0;

    struct Polynomial *P3;
    P3 = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    P3->t = (struct Term *)malloc((P1.n+P2.n) * sizeof(struct Term));

    while (i<P1.n && j<P2.n)
    {
        Display(*P3);
        if (P1.t[i].exp > P2.t[j].exp)
            P3->t[k++] = P1.t[i++];
        else if (P1.t[i].exp < P2.t[j].exp)
            P3->t[k++] = P2.t[j++];
        else
        {
            P3->t[k].exp = P1.t[i].exp;
            P3->t[k++].coeff = P1.t[i++].coeff + P2.t[j++].coeff;
        }
    }

    for (; i<P1.n; i++)
        P3->t[k++] = P1.t[i];

    for (; j<P2.n; j++)
        P3->t[k++] = P2.t[j];

    P3->n = k;
    return P3;
}

int main()
{
    struct Polynomial P1, P2, *P3;

    Create(&P1);
    Create(&P2);
    P3 = Add(P1, P2);

    printf("\n");
    Display(P1);
    printf("\n");
    Display(P2);
    printf("\n");
    Display(*P3);

    return 0;
}