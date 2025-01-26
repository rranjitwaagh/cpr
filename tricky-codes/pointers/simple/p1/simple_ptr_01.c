#include <stdio.h>

int main(void)
{
	int var = 10;;
	int *p = &var;

	printf("var 	= %d\n", var);
	printf("p 	= %d\n", p);
	printf("*p 	= %d\n", *p);
}

