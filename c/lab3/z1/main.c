#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "encryptCaeser.c"

// #define _GNU_SOURCE
// #include <stdlib.h>
// #include "getEncryptedLine.c"

int main()
{
    char msg[] = " to be or not to be";
    printf("%s\n", msg);
    encryptCaeser(msg);
    printf("%s\n", msg);

    // while (1)
    // {
    //     char *buffer = getEncryptedLine();
    //     if (buffer == NULL)
    //         return 0;

    //     printf("%s", buffer);
    //     free(buffer);
    // }

    return 0;
}