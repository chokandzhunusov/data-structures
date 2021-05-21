/*
 *  ======================
 *  Finding Multiple missing element in sorted Array
 *  ======================
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
    printf("Elemnets are: \n");
    for(int i=0; i<arr.length; i++)
    {
        printf("%d\n", arr.A[i]);
    }
}


void FindMultipleMissingElemInSeqOfNumbers(struct Array arr)
{
    int diff = arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]-i != diff)
        {
            while(diff < arr.A[i]-i)
            {
                printf("Missing element is: %d\n", i+diff);
                diff++;
            }
         }
    }
}


int main()
{
    struct Array arr;
    arr.size = 15;
    arr.length = 11;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    int elems[11] = {6, 7, 10, 11, 13, 14, 15, 16, 17};
    arr.A = elems;
    return 0;
}
