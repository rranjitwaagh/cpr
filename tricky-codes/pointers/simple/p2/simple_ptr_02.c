#include <stdio.h>

int main()
{
	int var = 100;
	int *p  = &var;

	printf("var = %d \t &var = 0x%x\n", var, &var);

	return(0);
}
