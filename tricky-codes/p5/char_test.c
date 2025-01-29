#include <stdio.h>

int main(void)
{
	char c1 = 'a';
	char c2 = 'b';
	char c = c1 + c2;

	if (c > 'c')
		printf("TRUE\n");
	else
		printf("FALSE\n");

	printf(" c = %d\n", c);

	return(0);
}
