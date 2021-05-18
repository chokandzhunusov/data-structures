/*
 *  ======================
 *  Set operations on Array
 *  ======================
 *  1. Union: no duplicates
        UNSORTED ELEMENTS: we should not have duplicates
        - m + m*n
        - copying elements from A to C, then first searching elements from B is it in C
        - in terms of n it will be n + n*n => O(n^2) quadratic, very slow operation, time consuming.
        SORTED ELEMENTS: we should not have duplicates
        - here we can use Merge procedure
        - Theta(m+n)
        - in terms of n it will be n+n => 2n => Theta(n)
 *  2. Intersection
        UNSORTED ELEMENTS: we should not have duplicates
        - Procedure: Take common elements of A and B and copy to C
        - Taking elements from A one by one(n) and looking it(n) in B will take O(n^2)
        SORTED ELEMENTS: we should not have duplicates
        - Similar to Merging, but not at all. Bcs coping only similar elements.
        - Theta(m+n) => Theta(n)
 *  3. Difference: what is only in A
        UNSORTED ELEMENTS: we should not have duplicates
        - Similar to `Intersection` => O(n^2)
        SORTED ELEMENTS: we should not have duplicates
        - Adopt Merge algorithm

 *  4. Set Membership
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


struct Array* UnionOfUnsortedElements(struct Array arr1, struct Array arr2)
{
    int i, j, k, t;
    t = arr1.length;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for(i=0; i<arr1.length; i++)
        arr3->A[i] = arr1.A[i];
    for(j=0; j<arr2.length; j++)
    {
        int met = 0;
        for(k=0; k<arr1.length; k++)
        {
            if(arr2.A[j] == arr3->A[k])
                met = 1;
        }
        if(met == 0)
        {
            arr3->A[t] = arr2.A[j];
            t++;
        }
    }
    arr3->length = t;
    arr3->size = 10;
    return arr3;
}


struct Array* UnionOfSortedElements(struct Array arr1, struct Array arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1.length && j<arr2.length)
    {
        if(arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else if(arr2.A[j] < arr1.A[i])
            arr3->A[k++] = arr2.A[j++];
        else
            arr3->A[k++] = arr1.A[i++];
            j++;
    }

    for(;i<arr1.length;i++)
        arr3->A[k++] = arr1.A[i];

    for(;j<arr1.length;j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}


struct Array* IntersectionOfSortedElements(struct Array arr1, struct Array arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1.length && j<arr2.length)
    {
        if(arr1.A[i] < arr2.A[j])
            i++;
        else if(arr1.A[i] > arr2.A[j])
            j++;
        else
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }

    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}


struct Array* DifferenceOfSortedElements(struct Array arr1, struct Array arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1.length && j<arr2.length)
    {
        if(arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else if(arr1.A[i] > arr2.A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1.length;i++)
        arr3->A[k++] = arr1.A[i];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}


struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;

    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];

    for(;j<arr2->length-1;j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}


int main()
{
    struct Array arr1={{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr2={{3, 6, 7, 15, 20}, 10, 5};
    struct Array *arr3;
    Display(*arr3);
    return 0;
}