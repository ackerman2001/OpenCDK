#include<stdio.h>
#include<stdlib.h>
#include "opcodes.h"

unsigned char *g_memory = NULL;

int main(int argc, char **argv)
{
	long R[0xF]; //registers
	int file_size;
	FILE *file;
	char *filename = argv[1]; //assign *filename to argument 1
	file = fopen(filename, "rb"); //load file
	g_memory = (unsigned char *) malloc(4294965097 * sizeof(char)); //4 GB of memory allocation.
	if (file == NULL) //if file doesn't exist
	{
		printf("Could not open file.\n");
		free(g_memory); //free memory
		exit(-1); //quit program with return -1
	}
	fseek(file, 0, SEEK_END); //point to the end of the file
	file_size = ftell(file); //get the value of file pointer
	fseek(file, 0, SEEK_SET); //point to the start of the file
	printf("file size: %d \n", file_size); //print file size
	for(int i = 1048576; i < file_size + 1048576; i = i + 1)
	{
		g_memory[i] = fgetc(file); //load data into memory
	}
	for(int pc = 0; pc*2 < file_size; pc = pc + 1)
	{
		unsigned char byte1 = g_memory[1048576 + pc];
		unsigned char byte2 = g_memory[1048577 + pc];
		execution((byte1 << 8) | byte2);
	}
	free(g_memory); //free memory
	return 0; //return value from a function.
}
