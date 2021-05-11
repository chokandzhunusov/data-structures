#include <stdio.h>
#include <stdlib.h>


// Define 3 elements of Array structure
struct Array {
    int *A;     // integer type pointer
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

int main() {
    // Initialize an Array and t integers
    struct Array arr;
    int n, i;

    // Prompt msg for user to enter the int to be size of an array
    printf("Enter size of and array: ");
    scanf("%d", &arr.size);

    // Set the size of an array with num taken from input of user
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    // Ask user how many numbers will be inserted
    printf("Enter number of numbers: ");
    scanf("%d", &n);

    // Start taking numbers to be set in Array
    printf("Enter all elements\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr.A[i]);
    arr.length = n;

    // Show all elements of an Array using function Display() created above
    Display(arr);
    return 0;
}