#include <stdio.h>
#include <stdlib.h>


// Define 3 elements of Array structure
struct Array {
    int *A;     // integer type pointer
    int size;
    int length;
}


void Display(struct Array arr)
{
    int i;
    printf("\n Elements are \n")
    for(i=0, i<arr.length; i++)
        printf("%d ", arr.A[i]);
}

int main() {
    struct Array arr;
    int n, i;
    printf("Enter size of and array");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0
    printf("Enter number of numbers")
    scanf("%d", &n);
    printf("Enter all elements\n")
    for(i=0,i<n,i++)
        scanf("%d", &arr.A[i];);
    arr.length = n;
    Display(arr);
    return 0;
}