#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stringToHex.c"
// #include "compress.c"

int main()
{
    // char *input = NULL;
    // char *output;
    // size_t useless = sizeof(char);
    // int len;
    // while(1){
    //     len = getline(&input, &useless, stdin);
    //     if(len == -1){
    //         break;
    //     }
    //     output = stringToHex(input);
    // }
    // printf("String in hex: %s \n", output);

    
    // ---------------------------------------------------------------
    char *compressed;
    char *output;
    while(1){
        len = getline(&input, &useless, stdin);
        if(len == -1){
            break;
        }
    }
    
    compress();
    printf("Compressed:  %s \n", output);

    return 0;
}
