/*
 *  ================================
 *  Validating password string for password
 *  ================================
 */


#include <stdio.h>


int Valid(char *password)
{
    int i;
    for (i=0; password[i]!='\0'; i++)
    {
        if(!(password[i]>=65 && password[i]<=90) && !(password[i]>=97 && password[i]<=122) && !(password[i]>=48 && password[i]<=57))
            return 0;
    }
    return 1;
}


int main()
 {
    char *password = "123?abc";

    if(Valid(password))
        printf("String is valid");
    else
        printf("String is NOT valid");

    return 0;
 }