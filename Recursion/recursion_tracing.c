/*
 *  ===================
 *  Recursion
 *  ===================
 *
 *  1. What is Recursion: must have `base condition`.
 *  2. Tracing Recursion: recursive functions are traced in forms of tree.
 *  3. Stack used in Recursion
 *  4. Time Complexity
 *  5. Recurrence Relation
 *
 *  Ascending: because of creation of call in stack comes one to another.
 *  Descending:           deletion of call                from top to bottom.
 */


#include <stdio.h>


// Tail recursion function eg to be analyzed using tree tracing
void func(int n)
{
    if (n > 0)
    {
        printf("\n%d", n);
        // calling time: Ascending(Loops have only this phase)
        func(n - 1);
        // returning time: Descending
    }
}


// Head recursion function eg to be analyzed using tree tracing
void func2(int n)
{
    if (n > 0)
    {
        // calling time: Ascending(Loops have only this phase)
        func2(n - 1);
        // returning time: Descending
        printf("\n%d", n);
    }
}


int main()
{
    int x = 3;
    printf("\nResult behaviour of an example function that first `prints` value and then calls itself:\n");
    func(x);
    printf("\nResult behaviour of an example function that first calls itself and then `prints` value:\n");
    func2(x);
}
