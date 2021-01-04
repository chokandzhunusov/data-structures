/*
 * Functions: peace of code that performs task.
 *            Group of related instructions.
 *            AKA: modules, procedures.
 */


#include <stdio.h>


/*
 * Monolithic Programming - Putting all code inside `main()`.
 * Modular/Procedural Programming - Dividing logic into small functions.
 */


int add(int a, int b)   // Line is called Prototype/Signature/Declaration of a function. a, b are `formal` params
// Lines below called: Definition/Elaboration of a function
{
    int c;
    c = a + b;
    return (c);
}


int main()
{
    int x, y, z;
    x = 10;
    y = 5;
    z = add(x, y);      // x, y are `actual` params
    printf("The sum is: %d", z);
}
