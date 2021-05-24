/*
 *  ====================================================
 *  Finding Duplicates in sorted Array and Counting them
 *  ====================================================
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


int main()
{
    struct Array E;
    E.size = 10;
    E.length = 10;
    int my_array[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    E.A = my_array;

    FindDuplicate(E);
    return 1;
}