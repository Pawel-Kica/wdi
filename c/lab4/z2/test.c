#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int get_value(FILE *pft, int idx) {
	fseek(pft, 0, SEEK_SET);
	int content;
	for (int i = 0; i <= idx; i++)
		fscanf(pft, "%i", &content);
	return content;
}

int main(int arg_count, char **arg_values){

	srand(time(NULL));
	// A file, B file, C(result) file
	if (arg_count != 4) {
		printf("Invalid data type\n");
		return 1;
	}
	
	FILE *ptf_A = fopen(arg_values[2], "r");
	FILE *ptf_B = fopen(arg_values[3], "r");
	FILE *ptf_C = fopen(arg_values[4], "w");
		
	int rows_A;
	int columns_A;
	int columns_B;

	rows_A = get_rows_number(ptf_A);
	columns_A = get_columns_number(ptf_A);
	columns_B = get_columns_number(ptf_B);
	
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
