/*
 *  ==================
 *  Reversing a string
 *  ==================
 */


#include <stdio.h>


void Reverse(char *word)
{
    char rword[7];
    int i, j;

    for (i=0; word[i]!='\0'; i++){}

    i -= 1;

    for (j=0; i>=0; i--, j++)
        rword[j] = word[i];

    rword[j] = '\0';
    printf("This a reverse: %s", rword);
}


void Reverse_2(char *word)
{
    char temp;
    int i, j;

    for (j=0; word[j]!='\0'; j++){}

    j -= 1;

    for (i=0; i<j; i++, j--)
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    printf("\nThis a reverse: %s", word);
}


int main()
 {
    char word[] = "python";
    Reverse(word);
    Reverse_2(word);

    return 0;
 }