/*
 *  ================================
 *  Introduction ti Strings in Clang
 *  ================================
 *  1. Character Set / ASCII codes (1-127=128 total, each 7 bits)
        - A -> Z => 65 -> 90
        - a -> z => 97 -> 122
        - zero -> nine => 48 -> 57
        - ENTER: 10, SPACE: 13, ESC: 27
    1.1 UNICODE
        - Are for all languages
        - ASCII is subset of UNICODE
        - Takes 2 bytes = 16 bits and represented as HEX 4 bit, so 4X4 bits

 *  2. Character Array
        - Data type is `char`
        - Single quote '', and only 1 byte
 *  3. Strings
 *  4. Creating a Strings
        - Initialization can be done:
            1. char name[10] = {'J', 'o', 'h', 'n', '\0'};
            2. char name[] = {'J', 'o', 'h', 'n', '\0'};
            3. char name[] = "John";
            3. char *name = "John";
 */


#include <stdio.h>


int main()
{
    char t = 'A';
    printf("%d", t);

    char X[] = {'A', 'B', 'C', 'D', 'E'}; // size will be taken from length if an array

    char name[10] = {'J', 'o', 'h', 'n'}; // Array of characters = String
    //              ['J', 'o', 'h', 'n', 0, 0, 0, 0, 0, 0]

    // How to know length of string?
    // In Clang strings are delimeted
    //              ['J', 'o', 'h', 'n', '\0', 0, 0, 0, 0, 0]
    //                                   String terminator
    //                                   Null char
    //                                   End of String char

    char name_2[10] = {'J', 'o', 'h', 'n', '\0'};
    //                                      by adding this becomes a string
    printf("%s", name_2);

    // Taking input from keyboard
    char name_input[10];
    scanf("\nPlease enter name %s", name_input);
    printf("%s", name_input);
    return 0;
}