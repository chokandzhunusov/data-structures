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


void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void InsertToSortedList(struct Array *arr, int x)
{
    int i=arr->length-1;
    if(arr->size==arr->length)
        return;
    while(i>=0 && arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

void REarrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length-1;
    while (i<j)
    {
        while(arr->A[i]<0)
            i++;
        while(arr->A[j]>=0)
            j--;
        if(i<j)
            Swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr={{2, 3, 5, 6, -3, 15, -1}, 10, 7};
    Display(arr);
    return 0;
}