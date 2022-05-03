#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int arg_count, char **arg_values){
	srand(time(NULL));
	// min_dim, max_dim
	if (arg_count != 3 || atoi(arg_values[2])<atoi(arg_values[1])) {
		printf("Invalid data type\n");
		return 1;
	}
	int d_min = atoi(arg_values[1]);
	int d_max = atoi(arg_values[2]);
	
	int size_1 = rand()%(d_max-d_min+1)+d_min;
	int size_2 = rand()%(d_max-d_min+1)+d_min;
	int size_3 = rand()%(d_max-d_min+1)+d_min;
	FILE *ptf = fopen("gen_A.txt", "w");
	for (int i = 0; i < size_1; i++) {
		for (int j = 0; j < size_2; j++)
			fprintf(ptf, "%i\t", rand()%100);
		fprintf(ptf, "\n");
	}
	fclose(ptf);
	ptf = fopen("gen_B.txt", "w");
	for (int i = 0; i < size_2; i++) {
		for (int j = 0; j < size_3; j++)
			fprintf(ptf, "%i\t", rand()%100);
		fprintf(ptf, "\n");
	}
	fclose(ptf);

	printf("Successfully generated %ix%i && %ix%i\n", size_1, size_2, size_2, size_3);
}
