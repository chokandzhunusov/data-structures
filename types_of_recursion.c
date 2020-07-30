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


 /* 1. Tail Recursion: if recursion called as last statement,
 *                     after that call nothing is performed.
 *                     Everything is performed at calling time only,
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

