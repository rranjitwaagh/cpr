#include <stdio.h>

int main(void)
{
	int var = 100;
	int *p = &var;
	int *q = p;

	printf("var = %d \t &var = %p\n", var, &var);

	/**
	 * Scaling Factor:
	 * Pointers get incremented by the size of the data type of the variable to
	 * which it is pointing to
	 */
	printf("p = %p \t q = %p\n", p, q);

	q++;
	printf("q = %p\n", q);
	printf("(int *) q - (int *) p = %p\n", q - p);

	/**
	printf("q + p = %p\n", q + p);
	printf("q * p = %p\n", q * p);
	*/

	printf("(char *)q - (char *)p = %ld\n", (char *)q - (char *)p);
	printf("(void *)q - (void *)p = %ld\n", (void *)q - (void *)p);

	return(0);
}
