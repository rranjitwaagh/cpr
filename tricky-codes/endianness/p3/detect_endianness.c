#include <stdio.h>

int main(void)
{
	unsigned int num = 1;
	unsigned char *pc = (unsigned char *) &num;
	//unsigned char *pc = &num;

	if (*pc == 1)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");

	return(0);
}
