#include <stdio.h>

int main(void)
{
	int var = 100;
	int *p  = &var;
	int **pp = &p;

	printf("var = %d\n", var);
	printf("&var = %p\n", &var);
	printf("p = %p\n", p);
	printf("&p = %p\n", &p);
	printf("*p = %d\n", *p);

	printf("pp = %p\n", pp);
	printf("&pp = %p\n", &pp);
	printf("*pp = %p\n", *pp);
	printf("**pp = %d\n", **pp);

	/**
	 * below we're just trying to understand the pointert variations
	 * this may lead to seg fault but we just need to understand and
	 * confirm the pointer access logic nothing else
	 */
	printf("*(*(&p)) = %d\n", *(*(&p)));
	printf("***&pp = %d\n", ***&pp);
	printf("***pp = %d\n", *(int *)**pp);

	return(0);
}

