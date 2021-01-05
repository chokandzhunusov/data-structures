/*
 *  ======================
 *  How to increase array size.
 *  ======================
 *
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *p = (int *)malloc(5*sizeof(int));
    int *q = (int *)malloc(10*sizeof(int));

    for(int i=0; i<5; i++)
        p[i] = i*3;

    for(int j=0; j<5; j++)
        q[j] = p[j];

    free(p);
    p = q;
    q = NULL;

    for(int k=0; k<5; k++)
        printf("%d", p[k]);
}