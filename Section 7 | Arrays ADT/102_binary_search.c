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
ANALYSIS OF BINARY SEARCH
=========================

- Time taken to run Binary Search depends on number of comparisons and it is at most `logn`

A = [4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43]
     0  1   2   3   4   5   6  7   8   9   10  11  12  13  14

FIRST WAY OF ANALYSIS
%%%%%%%%%%%%%%%%%%%%%%
                            7                              Internal pad(success search part)      =========>  1 depth
             3                          11                 I pad                                  =========>  2
        1           5             9             13         I pad                                  =========>  3
    0     2     4       6     8        6    12      14     I pad                                  =========>  4
  [][]   [][] [][]     [][] [][]     [][]  [][]    [][]    External pad(UNsuccess search part)    =========>  termination level of unsuccessful search
Successful searches:
    - Best min time  = O(1), element is in the middle
    - Worst max time = O(logn)
Unsuccessful searches:
    - time = O(logn)


SECOND WAY OF ANALYSIS
%%%%%%%%%%%%%%%%%%%%%%
NOTE: Inverse of power `x^y` is `log`

Assume n = 16; n: num of items in array
So, 16/2/2/2/2 = 1(element we were searching in BS)

16/2^4 = 1
2^4 = 16
4 = log16base2
    lognbase2


AVARAGE CASE
%%%%%%%%%%%%%
- Total time taken on all possible cases, divided by num of cases
- So, in depth 1 it is only one comparison made wby total 1 element
- In     depth 2 it is 1 comparison made by total of 2 elements
- In     depth 3 it is 2 comparison made by total of 4 elements
- In     depth 4 it is 3 comparison made by total of 8 elements
By that said:
    = 1 + 1*2 + 2*4 + 3*8
    = 1 + 2^1 + 2*2^2 + 3*2*3

      logn (height of tree)
    = SUMix2^i                / n
      i=1

    = (logn*2^logn) / n
    = (logn*n^log2base2) / n
    = logn

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