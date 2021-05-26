/*
 *  ==================================
 *  Quiz 3
 *  ==================================
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
    for (i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
}


void TwoNumsWithDiff(struct Array a, int s)
{
    int i, j;
    i = 0;
    j = 1;
    while (j<a.length)
    {
        if (a.A[j] - a.A[i] < s)
            j++;
        else if (a.A[j] - a.A[i] == s)
            break;
        else
            i++;
    }
    if (j<a.length)
        printf("Yes");
}

void FindSecondLargestElement(struct Array a)
{
    int i, l1, l2;
    l1=l2=0;

    for (i=0; i<a.length; i++)
    {
        if (a.A[i] > l1)
            l1 = a.A[i];
    }

    for (i=0; i<a.length; i++)
    {
        if (a.A[i] > l2 && a.A[i] < l1)
            l2 = a.A[i];
    }
    printf("%d, %d", l1, l2);
}


int main()
{
    struct Array a;
    a.size = 10;
    a.length = 10;
    int my_array[10] = {1, 2, 13, 4, 15, 6, 17, 8};
    a.A = my_array;

    return 1;
}