#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateBinaryFile(int size, int type, char *file_name) {
	FILE *ptf = fopen(file_name, "wb");
	int content;
	
	if (type) {
        int lowerRange = 33;
        int upperRange = 91;
	    for (int i = 0; i < size; i++)
	    {
			content = (rand()%(upperRange+1-lowerRange))+lowerRange;
			fwrite(&content, sizeof(char), 1, ptf);
		}
    }else {
	    for (int i = 0; i < size; i++){
			content = rand()%100;
			fwrite(&content, sizeof(int), 1, ptf);
		}
	}
	fclose(ptf);
    printf("Successfully generated \n");
}
void listBinaryFile(int size, int type, char *file_name){
    FILE *ptf = fopen(file_name, "rb");
	int content;
	if (type) {
	    for (int i = 0; i < size; i++)
	    {
            fread(&content, sizeof(char), 1, ptf);
            printf("%c", content);
		}
        printf("\n");
    }else {
	    for (int i = 0; i < size; i++){
            fread(&content, sizeof(int), 1, ptf);
            printf("%i\n", content);
        }
    }
	fclose(ptf);
    printf("Successfully listed\n");
}
int get(FILE *ptf, int idx, int size) {
	int content;
	fseek(ptf, size * idx,0);
	fread(&content, size, 1, ptf);
	return content;
}

void set(FILE *ptf, int idx, int size, int content) {
	fseek(ptf, size * idx,0);
	fwrite(&content, size, 1, ptf);
}

void sortBinaryFile(int length, int type, char *file_name) {
	FILE *ptf = fopen(file_name, "rb+");
    // type=1 char, type=0 int
	int v_size = type ? sizeof(char) : sizeof(int);
	
	for (int i = 0; i < length - 1; i++)
	{   
         for (int j = 0; j < length - i - 1; j++)
         {
            int el1 = get(ptf,j,v_size);
            int el2 = get(ptf,j+1,v_size);
            if (el1 > el2){
                int tmp = el1;
                set(ptf, j, v_size, el2);
                set(ptf, j+1, v_size, tmp);
            }
        }
    }
	fclose(ptf);
    printf("Successfully sorted\n");
}

int main(int argc, char **argv){
	srand(time(NULL));
	if (argc != 5) {
		printf("Invalid data type\n");
		return 1;
	} 
	int type;
	switch (argv[3][0]) {
		case 'i':
			type = 0;
			break;
		case 'c':
			type = 1;
			break;	
		default:
			printf("Invalid data type\n");
			return 1;
	}
	int size = atoi(argv[2]);
	switch (argv[4][0]) {
		case 'g':
			generateBinaryFile(size, type, argv[1]);
			break;
		case 'l':
			listBinaryFile(size, type, argv[1]);
			break;
		case 's':
			sortBinaryFile(size, type, argv[1]);
			break;
        case 'a':
			generateBinaryFile(size, type, argv[1]);
			listBinaryFile(size, type, argv[1]);
            printf("\n");
			sortBinaryFile(size, type, argv[1]);
			listBinaryFile(size, type, argv[1]);
            break;
		default:
			printf("Invalid operation\n");
			return 1;
	}
}
