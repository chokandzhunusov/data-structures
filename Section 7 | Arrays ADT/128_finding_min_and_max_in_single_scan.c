/*
 *  ==================================
 *  Finding Min and Max in single scan
 *  ==================================
 *  Time is diff and Case is diff
 *  1. Time(taking just degree)
 *      - O(n)
 *  2. Case
 *      - How many comparisons was made:
            Best case comparison if numbs was only decreasing order: n-1
            Worst case comparison if numbs was only increasing order: 2(n-1), means met `else if` case
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


void FindMinAndMax(struct Array E)
{
    int i, min, max;
    min=max=E.A[0];
    for (i=1; i<E.length; i++)
    {
        if (E.A[i] < min)           // comparison
            min = E.A[i];           // assignment
        else if (E.A[i] > max)      // comparison
            max = E.A[i];           // assignment
    }
    printf("Found min=%d and max=%d\n", min, max);
}


int main()
{
    struct Array E;
    E.size = 10;
    E.length = 10;
    int my_array[10] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    E.A = my_array;

    FindMinAndMax(E);

    return 1;
}