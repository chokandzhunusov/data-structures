/*
 *  ======================
 *  Set operations on Array
 *  ======================
 *  1. Union: should not copy both elements if same, just one of them
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


void InsertInAnArray(struct Array *arr, int x)
{
    int i = arr->length-1;
    while(arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
}


void InsertAtIndex(struct Array *arr, int index, int x)
{
    if(index<=arr->length && index>=0)
    {
        for(int i=arr->length; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}


int DeleteAtIndex(struct Array *arr, int index)
{
    int i, x;
    if(index<=arr->length && index>=0)
    {
        x = arr->A[index];
        for(i=index; i<arr->length; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return -1;
}


int LinearSearch(struct Array *arr, int x)
{
    for(int i=0; i<arr->length; i++)
    {
        if(arr->A[i] == x)
            return i;
    }
    return -1;
}


int Sum(struct Array *arr)
{
    int s = 0;
    for(int i=0; i<arr->length; i++)
        s += arr->A[i];
    return s;
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
    struct Array arr;
    int ch, x, d, s, index;
    printf("Please enter size of an Array");
    scanf("%d", &arr.size);
    arr.length = arr.size;
    arr.A=(int *)malloc(arr.size * sizeof(int));
    do
    {
        printf(" \n Menu to choose action on an Array: \n");
        printf("1: Insert\n");
        printf("2: Delete\n");
        printf("3: Search\n");
        printf("4: Sum\n");
        printf("5: Display\n");
        printf("6: Exit\n");


        printf("Please Choose Action on Array \n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Please enter index and number: ");
                scanf("%d%d", &index, &x);
                InsertAtIndex(&arr, index, x);
                break;
            case 2: printf("Please enter an index: ");
                scanf("%d", &index);
                d = DeleteAtIndex(&arr, index);
                printf("The deleted number is: %d", d);
                break;
            case 3: printf("Please enter number to search: ");
                scanf("%d", &x);
                index = LinearSearch(&arr, x);
                printf("The num you search is at index: %d", index);
                break;
            case 4: s = Sum(&arr);
                printf("The sum of all elemnts is: %d", s);
                break;
            case 5: Display(arr);
                break;
        }
    } while(ch<6);
    return 0;
}