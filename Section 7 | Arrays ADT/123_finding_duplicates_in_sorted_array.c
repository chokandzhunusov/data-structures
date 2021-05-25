/*
 *  ====================================================
 *  Finding Duplicates in sorted Array and Counting them
 *  ====================================================
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
    for(i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
}


void FindDuplicate(struct Array arr)
{
    int lastDuplicate = 0;
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i] == arr.A[i+1] && lastDuplicate != arr.A[i])
        {
            printf("Duplication found, it is: %d\n", arr.A[i]);
            lastDuplicate = arr.A[i];
        }
    }
}


void FindAndCountDuplicates(struct Array arr)
{
    int j;
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i] == arr.A[i+1])
        {
            j=i;
            // Do we consider following `while loop`? NO need.
            // It's covering just a part of an array.
            // Negligible
            while(arr.A[i] == arr.A[j])
                j++;
            printf("Duplication found, it is: %d, it repeates: %d times\n", arr.A[i], j-i);
            i = j-1;
        }
    }
}





int main()
{
    struct Array E;
    E.size = 10;
    E.length = 10;
    int my_array[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    E.A = my_array;

    FindAndCountDuplicates(E);
    return 1;
}