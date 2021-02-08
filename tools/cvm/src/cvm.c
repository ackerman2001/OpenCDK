#include<stdio.h>
#include<stdlib.h>

double g_memory[];

int main(int argc, char** argv)
{
	short opcode;
	int file_size;
	FILE *file;
	char *filename = argv[1]; //assign *filename to argument 1
	file = fopen(filename, "rb"); //load file
	if (file == NULL) //if file doesn't exist
	{
		printf("Could not open file.\n");
		exit(-1);
	}
	fseek(file, 0, SEEK_END); //point to the end of the file
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);
	printf("%d \n", file_size);
	return 0; //return value from a function.
}
