/*
 *  ======================
 *  Deleting from an Array
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

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}


/*
 *  Delete(index, x)
 *  x = A[index]
 *  for(i=index; i<Length-1; i++)
 *  {
 *      A[i] = A[i+1];              zero/n  shifting
 *  }
 *  Length --;
 *  ===============================
 *                                  min O(1)
 *                                  max O(n)
 */

int Delete(struct Array *arr, int index)
{
    int x=0;
    int i;
    if(arr->length>=index && index<arr->length)
    {
        x = arr->A[index];
        for(i=index; i<arr->length; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

int main()
{
    struct Array arr={{2, 3, 4, 5, 6}, 10, 5};
//    printf("%d", Delete(&arr, 1));
    Display(arr);
    return 0;
}