#include<stdio.h>

void execution(unsigned short opcode, unsigned char *memory, int *pc, long *R)
{
	unsigned char b[7];
	for(int i = 0; i < 7; i++)
	{
		b[i] = memory[pc + 1 + i];	
	}
	switch(opcode)
	{
		case 0x00:
			R[0xA] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			pc += 8;
			break;
		case 0xFF:
			while(memory[R[0xA]] != 0x00)
			for(int i = 0; memory[R[0xA]+i] != 0x00; i++)
			{
				printf("%c", memory[R[0xA] + i]);	
			}
			break;
	}
}
