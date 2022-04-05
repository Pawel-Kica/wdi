#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "encryptCaeser.c"


int main()
{
    char msg[] = " to be or not to be";
    printf("%s\n", msg);
    encryptCaeser(msg);
    printf("%s\n", msg);


    return 0;
}