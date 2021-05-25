/*
 *  ======================================================
 *  Finding Duplicates in UNSORTED Array and Counting them
 *  ======================================================
 *  = (n-1) + (n-2) +  (n-3) + ... + 3 + 2 + 1
 *  = n(n-1)/2
 *  = (n^2 - n)/2
 *  = O(n^2)
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


void FindDuplicatesInUnsortedArray(struct Array E)
{
    for (int i=0; i<E.length-1; i++)
    {
        if (E.A[i] != -1)
        {
            int count = 1;
            for (int j=i+1; j<E.length; j++)
            {
                if (E.A[i] == E.A[j])
                {
                    count++;
                    E.A[j] = -1;
                }
            }
            if (count > 1)
                printf("Duplication found, it is: %d, it repeates: %d times\n", E.A[i], count);
        }
    }
}


void FindDuplicatesInUnsortedArrayUsingHashTable(struct Array E, struct Array *H)
{
    for (int i=0; i<E.length-1; i++)
        H->A[E.A[i]]++;

    for (int j=0; j<H->length; j++)
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
    int my_array[10] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    E.A = my_array;

    // To Hash create an extra Array of length=highest element in array E, which is: 20.
    // So, last index of array to be used for Hashing must be 20 + 1.
    struct Array H;
    H.size = 9;
    H.length = 9;
    H.A = (int *)malloc(H.size * sizeof(int));

    return 1;
}