/*
 *  ============================================================
 *  Finding a pair with sum = K in an array with unique elements in a SORTED array
 *  ============================================================
 *  - If there are duplicates in an array,
      first you have to remove then and then perform operations
 *
 *  - O(n)
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


void FindPairOfElementsWithSumKInSortedArray(struct Array E, int k)
{
    int i, j;
    i=0;
    j = E.length - 1;
    while (i < j)
    {
        if (E.A[i] + E.A[j] > k)
            j--;
        else if (E.A[i] + E.A[j] < k)
            i++;
        else
        {
            printf("Found an elements %d + %d = %d in an array\n", E.A[i], E.A[j], k);
            i++;
            j++;
        }

    }
}


int main()
{
    struct Array E;
    E.size = 10;
    E.length = 10;
    int my_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    E.A = my_array;

    FindPairOfElementsWithSumKInSortedArray(E, 10);

    return 1;
}