/*
 *  =================================
 *  Comparing a string for Palindrome
 *  =================================
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


int IsPalindromeVer1(char *word)
{
    int i, j;

    for (i=0; word[i]!='\0'; i++){}
    i -= 1;

    char word_reverse_copy[i];

    for (j=0; i>=0; j++, i--)
        word_reverse_copy[j] = word[i];

    word_reverse_copy[j] = '\0';

    for (i=0; i<=j; i++)
    {
        if (word[i] != word_reverse_copy[i])
        {
            printf("The word `%s` is not a palindrome!\n", word);
            return -1;
        }
    }

    printf("Yep, the word `%s` is a palindrome!", word);
    return 1;
}


int IsPalindromeVer2(char *word)
{
    int i, j;
    for (i=0; word[i]!='\0'; i++){}
    i -= 1;

    for (j=0; j!=i; j++, i--)
    {
        if (word[i] != word[j])
        {
            printf("The word `%s` is not a palindrome!\n", word);
            return -1;
        }
    }

    printf("Yep, the word `%s` is a palindrome!", word);
    return 1;
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

    char word[] = "madam";
    IsPalindromeVer2(word);

    return 0;
 }