/*
 *  ======================
 *  Reverse and shoft and array
 *  ======================
 *  1. Reverse
        - One method to do it is creating extra array => 2n => O(n)
        - Second is interchange first and last elements
 *  2. Left shift
 *  3. Left rotate
 *  4. Right shift
 *  5. Right rotate
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


void ReverseArrayM1(struct Array *arr)
{
    int i, j;
    // Auxiliary array
    int *B;
    B = (int *)malloc(arr->length*sizeof(int));
    // Start of Reversing
    for(i=arr->length-1, j=0; i>=0; i--, j++)               // n+1
        B[j] = arr->A[i];                                   // n    we care only this part, where actual work is done
    // End of reversing

    for(int k=0; k<arr->length; k++)                        // n+1
        arr->A[k] = B[k];                                   // n    we care only this part, where actual work is done
                                                            // 2n => O(n)
}


void ReverseArrayM2(struct Array *arr)
{
    int i, j;
    for(i=0, j=arr->length-1; i<j; i++, j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}


void LeftShift(struct Array *arr)
{
    int i, temp;
    for(i=0; i<arr->length; i++)
    {
        if(i != 0)
        {
            arr->A[i-1] = arr->A[i];
        } else {
            printf("%d", temp);
            temp = arr->A[i];
        }
    }
    if(temp)
        arr->A[arr->length-1] = temp;
}


void RightShift(struct Array *arr)
{
    int i, temp;
    for(i=arr->length-1; i>=0; i--)
    {
        if(i==arr->length-1)
            temp = arr->A[i];
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}


int main()
{
    struct Array arr={{2, 3, 14, 5, 6}, 10, 5};
    Display(arr);
    return 0;
}