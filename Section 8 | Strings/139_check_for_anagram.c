/*
 *  ================================
 *  Check if given words are anagram
 *  ================================
 */


#include <stdio.h>


int CheckAnagram(char *word, char *word2)
{
    int i, j, match;

    for (i=0; word[i]!='\0'; i++){}
    for (j=0; word2[j]!='\0'; j++){}

    if (i!=j)
    {
        printf("Words are NOT anagram!");
        return -1;
    }
    else
    {
        for (i=0; word[i]!='\0'; i++)
        {
            match = 0;
            for (j=0; word[j]!='\0'; j++)
            {
                if (word[i] == word2[j])
                {
                    match = 1;
                    word2[j] = -1;
                    break;
                }
            }
            if (match == 0)
            {
                printf("Word is NOT anagram!");
                return -1;
            }
        }
    }
    printf("Word is an anagram!");
    return 1;
}


int CheckAnagramByHashing(char *word, char *word2)
{
    int i, j;

    for (i=0; word[i]!='\0'; i++){}
    for (j=0; word2[j]!='\0'; j++){}

    if (i!=j)
    {
        printf("Words are NOT anagram!");
        return -1;
    }

    int H[26] = {0,};

    for (i=0; word[i]!='\0'; i++)
    {
        H[word[i]-97]++;
    }

    for (j=0; word2[j]!='\0'; j++)
    {
        H[word2[j]-97]--;
        if (H[word2[j]-97] < 0)
        {
            printf("Words are NOT anagram!");
            return -1;
            break;
        }
    }

    printf("Words are anagram!");
    return 1;
}


int main()
 {
    char word[] = "decimal";
    char word2[] = "medical";

    return 0;
 }