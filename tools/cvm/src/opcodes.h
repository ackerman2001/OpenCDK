#include<stdio.h>

void execution(unsigned char opcode, unsigned char *memory, int *pc, long *R)
{
	unsigned long b[8];
	switch(opcode)
	{
		case 0x00:
			for(int i = 0; i < 8; i++) 
			{
				b[i] = memory[*pc + 1 + i];
			}
			R[0xA] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x01:
			for(int i = 0; i < 8; i++) 
			{
				b[i] = memory[*pc + 1 + i];
			}
			R[0xB] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0xFE:
			for(int i = 0; i < 2048; i++)
			{
				if(memory[R[0xA]+i] == 0x00)
				{
					break;
				}
				printf("%c", memory[R[0xA]+i]);	
			}
			break;
		case 0xFF:
			exit(0);
			break;
	}
}
