/*
 *  ======================
 *  Static vs Dynamic Array
 *  ======================
 *
 *  Size of Array that is created in Stack can not be changed.
 *  To change the size of an array Heap memory can be used.
 *
 */


#include <stdio.h>
#include <stdlib.h>



int main()
{
    int A[5]; // Allocates memory in stack during runtime, but size was decide while compiling
    for(int j=0; j<5; j++)
        printf("%d", A[j]);

    printf("\n");

    int *p; // Gets memory in stack.
    p = (int *)malloc(5 * sizeof(int)); // Points to location in Heap.
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 9;
    for(int i=0; i<5; i++)
        printf("%d", p[i]);
    free(p); // Don't forget to release unnecessary memory. Otherwise you'll stuck to memory leak issues.
    return 0;
}