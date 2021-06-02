/*
 *  =========================================
 *  Finding duplicates in a string using Bits
 *  =========================================
 *   - Bitwise Operations
 *      1. Left Shift <<
 *          H[] = {7, 6, 5, 4, 3, 2, 1, 0}
 *              most < significant bit < least
 *                128, 64, 32, 16, 8, 4, 2, 1
 *          H = H << 2 (shift by 2)
 *       store  modify
 *
 *      2. Bits ORing(Merging), where a=10; b=6
 *          a = 1010
 *          b = 0110
 *        a+b = 1110
 *
 *          - setting a bit inside of byte ON is called - merging
 *
 *      3. Bit ANDing(masking), , where a=10; b=6
 *          a = 1010
 *          b = 0110
 *        a+b = 0010
 *        a & b => not logical AND it is bitwise ANDing(single &)
 *
 *          - knowing/checking is bit inside of byte is ON/OFF is called - masking
 *              H = [0, 0, 0, 1, 0, 0, 0, 0] num in decimal = 16
 *              a = [0, 0, 0, 0, 0, 0, 0, 1] take a help of new byte and initialize it a=1
 *             Find is bit at 2 bit is ON/OFF
 *           a<<2 = [0, 0, 0, 0, 0, 1, 0, 0] shift to bit=2
 *          H & a = [0, 0, 0, 0, 0, 0, 0, 0] so, bit at 2 is OFF
 *
 */


#include <stdio.h>


void FindingDuplicatesUsingBits(char *word)
{
    int H=0, x=0, i;

    for (i=0; word[i]!='\0'; i++)
    {
        x = 1;
        x = x << (word[i] - 97);
        if ((x & H) > 0)
            printf("Duplication of letter: %c", word[i]);
        else
            H = x | H;
    }
}



int main()
 {
    char word[] = "finding";
    FindingDuplicatesUsingBits(word);

    return 0;
 }