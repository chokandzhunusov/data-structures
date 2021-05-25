/*
 *  =====================================================================
 *  Finding Duplicates in sorted Array and Counting them Using Hash Table
 *  =====================================================================
 *  O(n)
 */

#include <stdio.h>
#include <stdlib.h>


struct Array
{
    int *A;
    int size;
    int length;
};


void Display(struct Array arr)
{
    int i;
    printf("\n Elements are \n");
    for (i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
}


void FindDuplicatesAndCountThemUsingHashTechnique(struct Array E, struct Array *H)
{
    for (int i=0; i<E.length; i++)
        H->A[E.A[i]]++;

    for (int j=0; j<=H->length; j++)
    {
        if (H->A[j] > 1)
            printf("Duplication found, it is: %d, it repeates: %d times\n", j, H->A[j]);
    }
}


int main()
{
    struct Array E;
    E.size = 10;
    E.length = 10;
    int my_array[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    E.A = my_array;

    // To Hash create an extra Array of length=highest element in array E, which is: 20.
    // So, last index of array to be used for Hashing must be 20 + 1.
    struct Array H;
    H.size = 21;
    H.length = 21;
    H.A = (int *)malloc(H.size * sizeof(int));

    FindDuplicatesAndCountThemUsingHashTechnique(E, &H);
    return 1;
}