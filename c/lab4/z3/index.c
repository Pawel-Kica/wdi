#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>

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
	if (arg_count != 3) {
		printf("Invalid data type\n");
		return 1;
	}
	
	FILE *ptf_M = fopen(arg_values[1], "r");

	char* ptr_A_path = malloc(50*sizeof(char));
	char* ptr_B_path = malloc(50*sizeof(char));
	char* ptr_C_path = malloc(50*sizeof(char));

	fscanf(ptf_M, "%s %s %s",ptr_A_path,ptr_B_path,ptr_C_path);

	FILE *ptf_A = fopen(ptr_A_path, "r");
	FILE *ptf_B = fopen(ptr_B_path, "r");
	FILE *ptf_C = fopen(ptr_C_path, "w");
	
	int fd = fileno(ptf_C);

	int rows_A;
	int columns_A;
	int columns_B;

	rows_A = get_rows_number(ptf_A);
	columns_A = get_columns_number(ptf_A);
	columns_B = get_columns_number(ptf_B);

	fclose(ptf_M);

	int mode = atoi(arg_values[2]);
	int middle = rows_A/2;

	if(mode==1){
		columns_B = middle;
	}else{
		columns_B = rows_A - middle;
	}

	flock(fd, LOCK_EX);

	for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < columns_B; j++) {
			int sum = 0;
            for (int k = 0; k < columns_A; k++){
                int val_A = get_value(ptf_A, i * columns_A + k);
                int val_B = get_value(ptf_B, j + columns_B * k);
                sum += val_A*val_B;
            }
			fprintf(ptf_C, "%i\t", sum);
		}
		fprintf(ptf_C, "\n");
	}	
	
	flock(fd, LOCK_UN);
	fclose(ptf_A);
	fclose(ptf_B);
	fclose(ptf_C);
}
