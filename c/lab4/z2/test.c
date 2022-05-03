#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int get_value(FILE *f, int idx) {
	fseek(f, 0, SEEK_SET);
	int content;
	for (int i = 0; i <= idx; i++)
		fscanf(f, "%i", &content);
	return content;
}

int main(int arg_count, char **arg_values){
	srand(time(NULL));
    // A row count, A column count, B column count, A file, B file, C(excepted result) file

   if (arg_count != 7) {
		printf("Invalid data type\n");
		return 1;
	}
   
	int rows_A = atoi(arg_values[1]);
	int columns_A = atoi(arg_values[2]);
	int columns_B = atoi(arg_values[3]);
	FILE *ptf_A = fopen(arg_values[4], "r");
	FILE *ptf_B = fopen(arg_values[5], "r");
	FILE *ptf_C = fopen(arg_values[6], "r");
	
	for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < columns_B; j++) {
			int sum = 0;
            for (int k = 0; k < columns_A; k++){
                int val_A = get_value(ptf_A, i * columns_A + k);
                int val_B = get_value(ptf_B, j + columns_B * k);
                sum += val_A*val_B;
            }
            if(get_value(ptf_C,columns_B*i+j)==sum)
                continue;

            printf("test status - failure\n");
	        fclose(ptf_A);
            fclose(ptf_B);
            fclose(ptf_C);
            return 0;
		}
	}
    printf("test status - success\n");
	fclose(ptf_A);
	fclose(ptf_B);
	fclose(ptf_C);
}
