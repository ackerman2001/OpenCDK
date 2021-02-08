#include<stdio.h>
#include<stdlib.h>

unsigned char *g_memory = NULL;

int main(int argc, char** argv)
{
	short opcode;
	int file_size;
	FILE *file;
	char *file_name = argv[1]; //assign *filename to argument 1
	file = fopen(file_name, "rb"); //load file
	g_memory = malloc(sizeof(char));
	if (file == NULL) //if file doesn't exist
	{
		printf("Could not open file.\n");
		free(g_memory);
		exit(-1);
	}
	fseek(file, 0, SEEK_END); //point to the end of the file
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);
	printf("%d \n", file_size);
	for(int i = 1048576; i < file_size + 1048576; i = i + 1)
	{
		g_memory[i] = fgetc(file);
	}
	free(g_memory);
	return 0; //return value from a function.
}
