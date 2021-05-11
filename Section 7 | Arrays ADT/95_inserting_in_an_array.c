/*
 *  ======================
 *  Manipulations on Array
 *  ======================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *  Add(x)/Append(x)
 *  A[Length] = x;      1 operation
 *  Length ++;          1 operation
 *  ===============================
 *                      f(n) = 2
 *                      f(n) = 2n^0
 *                      O(n^0) = O(1)
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

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}


/*
 *  Insert(index, x)
 *  for(i=Length; i>index; i--)
 *  {
 *      A[i] = A[i-1];              zero/n  shifting
 *  }
 *  A[index] = x;                   1 operation
 *  Length ++;
 *  ===============================
 *                                  min O(1)
 *                                  max O(n)
 */

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if(arr->length>=index && index>=0)
    {
        for(i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int main()
{
    struct Array arr={{2, 3, 4, 5, 6}, 10, 5};
    // Append(&arr, 10);
    // Insert(&arr, 2, 7);
    Display(arr);
    return 0;
}