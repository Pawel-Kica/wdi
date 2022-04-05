#include "charToHex.c"

char* stringToHex(char *input)
{
    int length = strlen(input);

    char *output = malloc((length*2)+1);

    int j = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        output[j] = charToHex(input[i]/16);
        output[j+1] = charToHex(input[i]%16);
        j += 2;
    }

    output[j] = '\0';

    return output;
}