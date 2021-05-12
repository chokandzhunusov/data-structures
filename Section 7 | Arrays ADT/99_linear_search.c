/*
 *  ======================
 *  Linear Search
 *  ======================
 *  There are 2 methods on Arrays:
 *      1. Linear Search
 *      1. Binary Search
 *
 *  - To perform search on an array elements should be unique.
 *  - key: item that is going to be searched in an array.
 *  - result: location where key found.
 *
 *  ======================
 *  Improving Linear Search
 *  ======================
 *  - Transposition
 *      To improve Linear search, move it one index before by swap
 *  - Move to Front/Head
 *      Bring element found to first index by swap
 */

#include <stdio.h>
#include <stdlib.h>

/*
Size = 10
Length = 10
A = [2, 4, 5, 6, 8, 7, 9, 5, 4, 1]

for(i=0; i<Length; i++)
{
    if(A[i] == key)
        return i;
}
return -1;

======================================
Best case  => O(1)
Worst case => O(n)
Average case => O(n)     (1+2+3+...+n)/n
                         (n(n+1)/2)/n
                         (n+1)/2
*/


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


int LinearSearch(struct Array *arr, int x)
{
    for(int i=0; i<arr->length; i++)
    {
        if(arr->A[i] == x)
        {
            Swap(&arr->A[0], &arr->A[i]);
            return i;
        }
    }
    return -1;
}


int main()
{
    struct Array arr={{2, 3, 4, 5, 6}, 10, 5};
    printf("%d", LinearSearch(&arr, 5));
    Display(arr);
    return 0;
}