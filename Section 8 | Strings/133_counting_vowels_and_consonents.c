/*
 *  ==============================
 *  Counting Vowels and Consonants
 *  ==============================
 */


#include <stdio.h>


void CountVowelsAndConsonants(char A[] )
{
    int i, vcount=0, ccount=0;
    for (i=0; A[i]!='\0'; i++)
    {
        if(A[i]=='A' || A[i]=='E' || A[i]=='I' || A[i]=='O' || A[i]=='U' ||
           A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u')
            vcount += 1;
        else if((A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122))
            ccount += 1;
    }

    printf("Num of Vowels is: %d, consonants: %d", vcount, ccount);
}


void CountNumOfWords(char A[] )
{
    int i, words=1;
    for (i=0; A[i]!='\0'; i++)
    {
        if(A[i] == ' ' && A[i-1] != ' ')
            words += 1;
    }

    printf("Num of words in sentence is: %d", words);
}


int main()
 {
    char A[] = "How are you";
    CountVowelsAndConsonants(A);
    CountNumOfWords(A);
    return 0;
 }