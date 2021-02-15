#include<stdio.h>
#include<stdlib.h>
#include<GLFW/glfw3.h>

void execution(unsigned char opcode, unsigned char *memory, int *pc, long *R, GLFWwindow *window, char *CW, long *SP, unsigned char *stack)
{
	//variables
	unsigned long b[8];
	
	//combines b1-b8 (b[7]-b[0])
	for(int i = 0; i < 8; i++) 
	{
		b[i] = memory[*pc + 1 + i];
	}
	
	//Instructions
	switch(opcode)
	{
		case 0x00:
			R[0xA] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x01:
			R[0xB] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;	
		case 0x02:
			R[0xC] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
 		case 0x03:
			R[0xD] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x04:
			R[0xE] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
 		case 0x05:
			R[0xF] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x06:
			memory[R[0xA]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x07:
			memory[R[0xB]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x08:
			memory[R[0xC]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x09:
			memory[R[0xD]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x0A:
			memory[R[0xE]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x0B:
			memory[R[0xF]] = (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
			*(pc) += 8;
			break;
		case 0x0C:
			R[0xA] = R[0xA] + 1;
			break;
		case 0x0D:
			R[b[0]] = R[b[0]] + 1;
			*(pc) += 1;
			break;
		case 0x0F:
			R[b[0]] = R[b[0]] - 1;
			*(pc) += 1;
			break;
		case 0x10:
			R[0xA] = R[0xA] + R[b[0]];
			*(pc) += 1;
			break;
		case 0x11:
			R[0xA] = R[0xA] + ((b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0]);
			*(pc) += 1;
			break;
		case 0x12:
			stack[*SP] = *(pc) + 8;
			*(SP) += 1;
			*(pc) = ((b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0]) - 1;
			break;
		case 0x13:
			stack[*SP] = *(pc);
			*(SP) += 1;
			*(pc) = R[0xA] - 1;
			break;
		case 0x14:
			*(SP) -= 1;
			*(pc) = stack[*SP];
			break;
		case 0x15:
			R[0xA] = R[0xA] * R[b[0]];
			*(pc) += 1;
			break;
		case 0x16:
			if(R[b[0]] == R[b[1]])
			{
				*(pc) += 3;
			}
			break;
		case 0x17:
			if(R[b[0]] != R[b[1]])
			{
				*(pc) += 3;
			}
			break;
		case 0x18:
			R[0xA] = memory[R[0xB]];
			break;
		case 0x19:
			R[b0] = R[b1]
			break;
		case 0xFA:
			scanf("%d", &memory[R[0xA]]);
		case 0xFB:
			printf("%ld", (b[7] << 56) | (b[6] << 48) | (b[5] << 40) | (b[4] << 32) | (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0]);
			*pc += 8
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
