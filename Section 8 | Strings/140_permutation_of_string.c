/*
 *  =======================
 *  Permutation of a string
 *  =======================
 *
 *                STATE SPACE TREE OF [A, B, C]
 *                       0
 *          A            B            C
 *        B   C        A   C        B   A
 *      C      B     C      A     A       B
 *    ABC     ACB   BAC    BCA   CBA     CAB    (LEAF NODES)
 *
 *
 *   Getting results by - BACKTRACKING
 *   Finding All possible permutations[A, B, C] - BRUTE FORCE
 *
 *  - Have to use RECURSION to achieve BACKTRACKING
 *  - And with help of BACKTRACKING we perform BRUTE FORCE
 */


#include <stdio.h>


void Perm(char *word, int k)
{
    static char result[10];
    static int flag[10] = {0,};

    if (word[k] == '\0')
    {
        result[k] = '\0';
        printf("%s\n", result);
    }
    else
    {
        for (int i=0; word[i]!='\0'; i++)
        {
            if (flag[i] == 0)
            {
                flag[i] = 1;
                result[i] = word[k];
                Perm(word, k+1);
                flag[i] = 0;
            }
        }
    }
}


void swap(char *word, int a, int b)
{
    char temp;
    temp = word[a];
    word[a] = word[b];
    word[b] = temp;
}


void PermMethod2(char *word, int l, int h)
{
    int i;

    if (l == h)
        printf("%s\n", word);
    else
    {
        for (i=l; i<=h; i++)
        {
            swap(word, l, i);
            PermMethod2(word, l+1, h);
            swap(word, l, i);
        }
    }
}


int main()
{
   char S[] = "ABC";
   PermMethod2(S, 0, 2);
   return 0;
}