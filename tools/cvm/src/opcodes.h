#include<stdio.h>
#include<stdlib.h>
#include<GLFW/glfw3.h>

void execution(unsigned char opcode, unsigned char *memory, int *pc, long *R, GLFWwindow *window, int *CW)
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
		case 0x02:
			for(int i = 0; i < 8; i++) 
			{
				b[i] = memory[*pc + 1 + i];
			}
			R[0xC] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
 		case 0x03:
			for(int i = 0; i < 8; i++) 
			{
				b[i] = memory[*pc + 1 + i];
			}
			R[0xD] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x04:
			for(int i = 0; i < 8; i++) 
			{
				b[i] = memory[*pc + 1 + i];
			}
			R[0xE] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
 		case 0x05:
			for(int i = 0; i < 8; i++) 
			{
				b[i] = memory[*pc + 1 + i];
			}
			R[0xF] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x06:
			for(int i = 0; i < 8; i++)
			{
				b[i] = memory[*pc + 1 + i];
			}
			memory[R[0xA]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
		case 0x07:
			for(int i = 0; i < 8; i++)
			{
				b[i] = memory[*pc + 1 + i];
			}
			memory[R[0xB]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
		case 0x08:
			for(int i = 0; i < 8; i++)
			{
				b[i] = memory[*pc + 1 + i];
			}
			memory[R[0xC]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
		case 0x09:
			for(int i = 0; i < 8; i++)
			{
				b[i] = memory[*pc + 1 + i];
			}
			memory[R[0xD]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
		case 0x0A:
			for(int i = 0; i < 8; i++)
			{
				b[i] = memory[*pc + 1 + i];
			}
			memory[R[0xE]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
		case 0x0B:
			for(int i = 0; i < 8; i++)
			{
				b[i] = memory[*pc + 1 + i];
			}
			memory[R[0xF]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
		case 0x0C:
			R[0xA] = R[0xA] + 1;
		case 0x0D:
			R[b[0]] = R[b[0]] + 1;
			*(pc) += 1;
		case 0x0F:
			R[b[0]] = R[b[0]] - 1;
			*(pc) += 1;
			break;
		case 0x10:
			R[0xA] = R[0xA] + R[b[0]];
			*(pc) += 1;
			break;
		case 0x11:
			R[0xA] = R[0xA] + ((b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0])
			*(pc) += 1;
			break;
		case 0xFC:
			*CW = 1;
			break;
		case 0xFD:
			scanf("%s", &memory[R[0xA]]);
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
