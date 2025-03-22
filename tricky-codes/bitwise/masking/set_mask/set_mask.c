#include <stdio.h>

unsigned int get_int_byte_mak(unsigned char byte)
{
	unsigned int mask = 0xFF;

	if (byte <= 4) {
		// byte_num * number of bits per byte
		mask = mask << ((byte - 1) * 8);
		printf("mask generated 0x%x\n", mask);
	} else {
		printf("Cannot create set mask for more than 4 bytes\n");
	}

	return (mask);
}

int main(void)
{
	unsigned int victim = 0xabcdef23;
	unsigned int mask;// = (0xFF << 8);	// update second word

	printf("Before : victim : 0x%x, mask : 0x%x\n", victim, mask);

	mask = get_int_byte_mak(1);
	printf("1. 0x%x | 0x%x = 0x%x\n", victim, mask, victim | mask);

	mask = get_int_byte_mak(2);
	printf("2. 0x%x | 0x%x = 0x%x\n", victim, mask, victim | mask);

	mask = get_int_byte_mak(3);
	printf("3. 0x%x | 0x%x = 0x%x\n", victim, mask, victim | mask);

	mask = get_int_byte_mak(4);
	printf("4. 0x%x | 0x%x = 0x%x\n", victim, mask, victim | mask);

	return(0);
}

