/*
 *  ===============================================================================
 *  Finding a pair with sum = K in an array with unique elements in UNSORTED array
 *  ==============================================================================
 *  - If there are duplicates in an array,
      first you have to remove then and then perform operations
 *
 *  COMPLEXITY
 *  = (n-1) + (n-2) +  (n-3) + ... + 3 + 2 + 1
 *  = n(n-1)/2
 *  = (n^2 - n)/2
 *  = O(n^2) Quadratic time taking procedure
 *  ===========================================
 *  Hash technique will take O(n)
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


void FindPairOfElementsWithSumK(struct Array E, int k)
{
    for (int i=0; i<E.length-1; i++)
    {
        for (int j=i+1; j<E.length; j++)
            {
                if (E.A[i] + E.A[j] == k)
                    printf("Found an elements %d + %d = %d in an array\n", E.A[i], E.A[j], k);
            }
    }
}


void FindPairOfElementsWithSumKUsingHashing(struct Array E, struct Array *H, int k)
{
    for (int i=0; i<E.length; i++)
    {
        int indexOfNumNeeded = k - E.A[i];
        if (indexOfNumNeeded >= 0 && indexOfNumNeeded <= H->length)
        {
            if (H->A[indexOfNumNeeded] != 0)
                printf("Found an elements %d + %d = %d in an array\n", E.A[i], indexOfNumNeeded, k);
        }
        H->A[E.A[i]]++;
    }
}

int main()
{
    struct Array E;
    E.size = 10;
    E.length = 10;
    int my_array[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    E.A = my_array;

    // To Hash create an extra Array of length=highest element in array E, which is: 20.
    // So, last index of array to be used for Hashing must be 20 + 1.
    struct Array H;
    H.size = 9;
    H.length = 9;
    H.A = (int *)malloc(H.size * sizeof(int));

    return 1;
}