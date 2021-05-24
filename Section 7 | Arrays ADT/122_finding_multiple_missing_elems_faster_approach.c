/*
 *  ==========================================================================
 *  Finding Multiple missing element in sorted Array using Hash like approach
 *  ==========================================================================
 *  - Loop through array and mark Hash Table.
 *  - Marking Hash Table is constant, just access by index.
 *  - And then loop to find missing elements.
 *  - O(2n) => O(n)
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
    for(i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
}


void FindMissingElementsUsingHashLikeApproach(struct Array *E, struct Array *H, int n)
{
    for(int i=0; i<n; i++)
        H->A[E->A[i]]++;

    for(int j=1; j<H->length; j++)
    {
        if(H->A[j] == 0)
            printf("Missing element: %d\n", j);
    }
}


int main()
{
    struct Array E;
    E.size = 10;
    E.length = 10;
    int my_array[10] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    E.A = my_array;

    int l = 1;  // Lowest elem in seq E->A is: 1
    int h = 12; // Highest elem in seq E->A is: 12
    int n = 10;

    struct Array H;
    H.size = 12;
    H.length = 12;
    H.A = (int *)malloc(H.size * sizeof(int));
    FindMissingElementsUsingHashLikeApproach(&E, &H, n);
    return 1;
}