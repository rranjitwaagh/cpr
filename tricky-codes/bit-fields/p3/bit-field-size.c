#include <stdio.h>

struct bits1 {
	unsigned int  f1:1,
		      f2:1,
		      f3:1;
	char f4;		// 29 bits are still available from int, so no extra byte is needed
};

int main(void)
{
	printf("Size of strcut bits1 is : %d\n", sizeof(struct bits1));


	return(0);
}

