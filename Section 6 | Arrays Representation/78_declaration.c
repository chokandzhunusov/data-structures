#include <stdio.h>

int A[5];   // Garbage/Unknown/Random values will be given

int A2[5] = {1, 2, 3, 4, 5};     // Values will be set during run-time

int A3[5] = {1, 2};      // First two indices will be set and others will be set to 0(zero)

int A4[] = {1, 2, 3, 4, 5};   // Array of size of elements will be created


int main()
{
    // Array element access #1
    // printf("%d", A2[3]);

    // Traversing an Array and accessing it's elements
    // for(int i=0; i<5; i++)
        // printf("%d", A2[i]);

    // Array element access #2
    // printf("%d", 3[A2]);

    // Array element access #3
    // printf("%d", *(A2 + 3));

    // TODO
    // Print addresses of array `A`
    for(int j=0; j<5; j++)
        printf("%u \n", &A[j]);

    return 0;
}