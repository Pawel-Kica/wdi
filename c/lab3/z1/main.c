#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "encryptCaeser.c"
#include "encryptLineByLine.c"

int main()
{
    char msg[] = " to be or not to be";
    printf("%s\n", msg);
    encryptCaeser(msg);
    printf("%s\n", msg);

    while(1){
        char *result = encryptLineByLine();

        if(result==NULL)
            return 0;

        printf("%s",result);
    }
    
    return 0;
}
