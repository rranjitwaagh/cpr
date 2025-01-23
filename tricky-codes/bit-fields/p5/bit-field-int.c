#include <stdio.h>


int main(void)
{
	struct bits {
		int f1:3;
		unsigned int f2:1;
	} b = {5, 1};
		
	printf("f1:%d \t f2:%d \n", b.f1, b.f2);

	return(0);
}

