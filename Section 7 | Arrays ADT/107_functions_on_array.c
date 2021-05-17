/*
 *  ======================
 *  Get(), Set(), Max(), Min(), Avrg() functions on array
 *  ======================
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


int Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
}


void Set(struct Array *arr, int index, int x)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index] = x;
    }
}


/*
 - For unsorted list we have to check all elements
 Max():
    max = A[0];                     ====> 1
    for(i=1; i<length; i++)         ====> n
    {
        if(A[i]>max)                ====> n-1
            max = A[i];
    }
    return max;                     ====> 1

                                    ====> f(n) = 2n +1
                                               = O(n)
*/

int Max(struct Array arr)
{
    int m = arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i] > m)
            m = arr.A[i];
    }
    return m;
}


int Min(struct Array arr)
{
    int m = arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i] < m)
            m = arr.A[i];
    }
    return m;
}


int Sum(struct Array arr)
{
    int t = 0;
    for(int i=0; i<arr.length; i++)
        t += arr.A[i];
    return t;
}


float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}


int main()
{
    struct Array arr={{2, 3, 14, 5, 6}, 10, 5};
//    printf("%f", );
    Display(arr);
    return 0;
}