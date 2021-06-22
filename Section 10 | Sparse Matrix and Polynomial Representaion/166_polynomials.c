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
}


struct Polynomial
{
    int n;  // number of terms
    struct Term *t;
}


void Create(struct Polynomial *P)
{
    scanf("Please enter num of terms: %d \n", &P->n);
    P->t = (struct Term *)malloc(P->n * sizeof(struct Element));
    for (int i=0; i<P->n; i++)
    {
        printf("Enter coefficient and exponent for term: %d", i+1);
        scanf("%d%d\n", &P->t[i].coeff, &P->t[i].exp);
    }
}


int Evaluate(struct Polynomial P, int x)
{
    int i=sum=0;
    for (i; i<P.n; i++)
        sum += P.t[i].coeff * (x * P.t[i].exp);
    return sum;
}


int Add(struct Polynomial P1, struct Polynomial P2)
{
    int i, j, k;
    i=j=k=0;

    while (P1.n<i && P2.n<j)
    {
        if (P1.t[i].exp > P2.t[i].exp)
        {
            P3.t[k].coeff = P1.t[i].coeff
            P3.t[k++].exp = P1.t[i++].exp;
        }
        else if (P1.t[i].exp < P2.t[i].exp)
        {
            P3.t[k].coeff = P2.t[j++].coeff;
            P3.t[k++].exp = P1.t[j++].exp;
        }
        else
        {
            P3.t[k].coeff = P1.t[i].coeff + P2.t[j++].coeff;
            P3.t[k++].exp = P1.t[i].exp;
        }
    }
}

int main()
{
    struct Polynomial P;
    Create(&P);
    return 0;
}