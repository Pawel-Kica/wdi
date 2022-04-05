#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stringToHex.c"

int main()
{
    char input[300]="123pawel785";

    char *output;

    // char* input = NULL;
    // size_t useless1 = sizeof(NULL);
    // int length = 0;

	// int length = getline(&buffer, &useless1, stdin);

    // scanf("Enter a string: \n", input);

    output = stringToHex(input);

    printf("String in hex: %s\n", output);

    return 0;
}
