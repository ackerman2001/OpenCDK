#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	FILE *file;
	char *filename = argv[1]; //assign *filename to argument 1
	file = fopen(filename, "rb"); //load file
	if (file == NULL)
	{
		printf("Could not open file.\n");
		exit(-1);
	}
	return 0; //return value from a function.
}
