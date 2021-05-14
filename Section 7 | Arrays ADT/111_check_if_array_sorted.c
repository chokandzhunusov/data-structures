/*
 *  ======================
 *  Checking an array if sorted
 *  ======================
 *  1. Inserting in a Sorted Array
 *  2. Checking if an Array is Sorted
 *  3. Arranging on left and right side side
 */

#include <stdio.h>
#include <stdlib.h>


struct Array
{
    int A[10];
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


void InsertToSortedList(struct Array *arr, int x)
{
    int i = arr->length-1;
    while(x < arr->A[i])
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
}

int main()
{
    struct Array arr={{2, 3, 14, 5, 6}, 10, 5};
    Display(arr);
    return 0;
}