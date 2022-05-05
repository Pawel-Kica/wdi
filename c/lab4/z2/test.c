#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int get_value(FILE *ptf_M, int idx) {
	fseek(ptf_M, 0, SEEK_SET);
	int content;
	for (int i = 0; i <= idx; i++)
		fscanf(ptf_M, "%i", &content);
	return content;
}

int get_rows_number(FILE *ptf_f){
	int length=0;
    char* input = NULL;
    size_t useless = 128;
    int line_counter = 0;
	while(1){
        length = getline(&input, &useless, ptf_f);
		if(length == -1)
				break;
		line_counter++;
    }
	return line_counter;
}

int get_columns_number(FILE *ptf_f){
	fseek(ptf_f, 0, SEEK_SET);
	int length=0;
    char* input = NULL;
    size_t useless = 128;
    length = getline(&input, &useless, ptf_f);

	int counter = 1;
    for (int i = 0; i < length; i++)
	{
		if(input[i]==' ')
		{
			counter++;		
		}
	}

	return counter;
}

int main(int arg_count, char **arg_values){

	srand(time(NULL));
	// A file, B file, C(result) file
	if (arg_count != 4) {
		printf("Invalid data type\n");
		return 1;
	}
	
	FILE *ptf_A = fopen(arg_values[1], "r");
	FILE *ptf_B = fopen(arg_values[2], "r");
	FILE *ptf_C = fopen(arg_values[3], "r");
		
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
