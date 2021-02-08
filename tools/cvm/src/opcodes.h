#include<stdio.h>

void execution(unsigned short opcode, unsigned char *memory, int *bc, long *R)
{
	//printf("pc: %x : 0x%.4x \n", *bc/2, opcode);
	//for debugging
	switch(opcode&0xFF)
	{
		case 0x0D:
			R[0xA] =  opcode>>8;
			break;
		case 0xFF:
			for(long int i=0; i<R[opcode>>12]; i++)
			{
				printf("%c", memory[1048576+*bc+2+i]);
			}
			printf("\n");
			break;
	}
}
