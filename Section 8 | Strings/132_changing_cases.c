/*
 *  ==========================
 *  Changing cases in a string
 *  ==========================
 */


#include <stdio.h>


int main()
 {
    char A[] = "WeLCOme";
    int i;
    int u, l;
    u = 65;
    l = 97;
    for (i=0; A[i]!='\0'; i++)
    {
        if (A[i] >= 65 && A[i] <= 90)
            A[i] += 32;
        else if (A[i] >= 'a' && A[i] <= 122)
            A[i] -= 32;
    }

    printf("Word in lowercase is: %s", A);

    return 0;
 }