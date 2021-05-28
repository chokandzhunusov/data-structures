/*
 *  ==================
 *  Reversing a string
 *  ==================
 */


#include <stdio.h>


void CaseSensitiveComparisonOfWords(char *word1, char *word2)
{
    int i, j;

    for (i=0, j=0; word1[i]!='\0' && word2[j]!='\0'; i++, j++)
    {
        if (word1[i] != word2[j])
            break;
    }
    if (word1[i] == word2[j])
        printf("The words are same");
    else if (word1[i] < word2[j])
        printf("Smaller");
    else
        printf("Greater");
}


int Palindrome(char *word)
{
    return 0;
}


int main()
 {
    char word1[] = "painter";
    char word2[] = "painting";
    CaseSensitiveComparisonOfWords(word1, word2);

    return 0;
 }