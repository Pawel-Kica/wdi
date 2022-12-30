// ./main <size> <file.src> <file.trg>
#include <stdio.h>
#include <stdlib.h>
int main(int argsc, char* argsv[])
{
  if (argsc != 4) {
    return 1;
  }
  int buffer_size = atoi(argsv[1]);
  FILE* s_f = fopen(argsv[2], "r");
  FILE* trg_file = fopen(argsv[3], "w");
  if (!s_f) {
    printf("source file error");
    printf("\n")
    return 1;
  }
  if (!trg_file) {
    printf("targetfile error");
    printf("\n")
    return 1;
  }
  char* buffer = malloc(buffer_size * sizeof(char));
  int counter = 0;
  while (!feof(s_f)) {
    if(counter>buffer_size){
      break;
    }
    int bytes_read = fread(buffer, sizeof(char), buffer_size, s_f);
    fwrite(buffer, sizeof(char), bytes_read, trg_file);
    counter++;
  }
  fclose(s_f);
  fclose(trg_file);
  free(buffer);
  return 0;
}
