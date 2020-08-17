/*
 *  ======================
 *  Types of Recursion:
 *  ======================
 *
 *  1. Tail recursion
 *  2. Head recursion
 *  3. Tree recursion
 *  4. Indirect recursion
 *  5. Nested recursion
 *
 */


 #include <stdio.h>


 /* 1. Tail Recursion: if recursion called as `last` statement,
 *                     after that call nothing is performed.
 *                     Everything is performed at `calling` time only,
 *                     at returning time nothing performed.
 *                     Usage of loop is better in terms of space complexity.
 */

// Will take: O(n) in terms of time, and O(n) in terms of space
void tail_recursion(int n)
{
    if (n > 0)
    {
        printf("\n%d", n);
        tail_recursion(n - 1);
    }
}

// Will take: O(n) in terms of time, and O(1) in terms of space
void tail_loop(int n)
{
    while (n > 0)
    {
        printf("\n%d", n);
        n--;
    }
}


/* 2. Head Recursion: if recursion called as `first` statement,
 *                     nothing before.
 *                     Everything is performed at `return` time only.
 */


// Can not be easily converted to loop
void head_recursion(int n)
{
    if (n > 0)
    {
        head_recursion(n - 1);
        printf("\n%d", n);
    }
}


void head_loop(int n)
{
    int i = 1;
    while(i<=n)
    {
        printf("\n%d", i);
        i++;
    }
}


int main()
{

}