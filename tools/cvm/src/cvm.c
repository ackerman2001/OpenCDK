#include<stdio.h>
#include<stdlib.h>
#include<GLFW/glfw3.h>
#include "opcodes.h"

unsigned char *g_memory = NULL;
unsigned char *g_stack[1048576];

int main(int argc, char** argv)
{
	GLFWwindow *window;
	long R[0xF]; //registers
	int file_size;
	char CW = 0;
	FILE *file;
	char *filename = argv[1]; //assign *filename to argument 1
	file = fopen(filename, "rb"); //load file
	g_memory = (unsigned char *) malloc(2147483648 * sizeof(char)); //2 GB of memory allocation.
	if (file == NULL) //if file doesn't exist
	{
		printf("Could not run a program.\n");
		free(g_memory); //free memory
		exit(-1); //quit program with return -1
	}
	if (!glfwInit())
	{
		printf("Could not initiate libraries.\n");
		exit(-1);
	}
	fseek(file, 0, SEEK_END); //point to the end of the file
	file_size = ftell(file); //get the value of file pointer
	fseek(file, 0, SEEK_SET); //point to the start of the file
        //printf("file size: %d \n", file_size);
       	//print file size
	for(int i = 0; i < file_size; i = i + 1)
	{
		g_memory[i] = fgetc(file); //load data into memory
	}
	for(int pc = 0; pc < file_size; pc = pc + 1)
	{
		execution(g_memory[pc], g_memory, &pc, R, window, &CW);
		if(CW == 1) 
		{
			window = glfwCreateWindow(640,480, "Hello World", NULL, NULL);
			CW == 0;
		}
	}
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	free(g_memory); //free memory
	return 0; //return value from a function.
}
