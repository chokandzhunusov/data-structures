/*
 *  ==============================
 *  Finding duplicates in a string
 *  ==============================
 *  1. Compare with other letters => O(n^2)
 *  2. Using HashTable as counting => O(n)
 *  3. Using Bits
 */


#include <stdio.h>


void FindingDuplicates(char *word)
{
    int i, j;

    for (i=0; word[i]!='\0'; i++)
    {
        for (j=i+1; word[j]!='\0'; j++)
        {
            printf("%c, %c\n", word[i], word[j]);
            if (word[i] == word[j])
            {
                printf("Found duplication for: %c\n", word[i]);
                word[j] = -1;
            }
        }
    }
    printf("Finished search of duplicated chars");
}


void FindingDuplicatesByHashing(char *word)
{
    int i, j;

    int H[26] = {0};

    for (i=0; word[i]!='\0'; i++)
        H[word[i]-97] += 1;

    for (j=0; j<26; j++)
    {
        if (H[j]>1)
            printf("Found duplication for: %c\n", j + 97);
    }
}



int main()
 {
    char word[] = "finding";
    FindingDuplicatesByHashing(word);

    return 0;
 }