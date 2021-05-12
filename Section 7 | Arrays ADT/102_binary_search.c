/*
 *  ======================
 *  Binary Search
 *  ======================
 *  - Required
 *      items must be sorted
 *      params needed: key, low, high, mid=[(l+h)/2]
 */

#include <stdio.h>
#include <stdlib.h>



/*
A = [4, 8, 10, 15, 18, 21]

*/


/*
Iterative Method
====================================
Algorithm BinarySearch(l, h, key)
{
    while l <= h
    {
        mid = (l+h)/2;
        if(key==A[mid])
            return mid;
        else if(key<A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}


Recursive Method
====================================
Algorithm RBinarySearch(l, h, key)
{
    if(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key<A[mid])
            return RBinarySearch(l, mid-1, key);
        else
            return RBinarySearch(mid+1, h, key);
    }
    return -1
}



NOTE: Tail Recursions and Loops are same. It's better to do with loop. (Above recursion is - tail)
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


int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length-1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}


int RBinarySearch(int arr[], int l, int h, int key)
{
    if(l<=h)
    {
        int mid = (l+h)/2;
        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            return RBinarySearch(arr, l, mid-1, key);
        else
            return RBinarySearch(arr, mid+1, h, key);
    }
    return -1;
}


int main()
{
    struct Array arr={{2, 3, 4, 5, 6}, 10, 5};
    // printf("%d", RBinarySearch(arr.A, 0, arr.length, 9));
    Display(arr);
    return 0;
}