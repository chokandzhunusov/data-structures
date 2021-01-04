/*
 * Structure: Grouping data
 */


#include <stdio.h>


struct Rectangle
{
    int length;     // eg: 2 bytes
    int breadth;    // eg: 2 bytes
};


struct Card
{
    int face;
    int shape;
    int color;
};


int main()
{
    struct Rectangle r = {10, 5};
    r.length = 15;
    printf("Area of rectangle is %d", r.length * r.breadth);

    struct Card deck[52] = {{1, 0, 0}};
    printf("The face is \n%d", deck[0].face);
}