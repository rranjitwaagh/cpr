#include <stdio.h>

int main(void)
{
	int var = 100;
	int *p = &var;
	int **pp = &p;

	printf("var = %d \t var+1 = %d\n", var, var + 1);

	/**
	 * Pointers get incremented by the size of the data type of the variable to
	 * which it is pointing to
	 */
	printf("p = %p \t p+1 = %p\n", p, p+1);
	printf("pp = %p \t pp+1 = %p\n", pp, pp+1);

	return(0);
}
