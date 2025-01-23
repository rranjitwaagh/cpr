#include <stdio.h>

struct bits1 {
	unsigned char	f1:1,
			r1:1,
			f2:2,
			r2:1,
			f3:3;
};

struct bits2 {
	unsigned char	f1:1;
	unsigned char	r1:1;
	unsigned char 	f2:2;
};

struct bits3 {
	unsigned char f1:1;
	unsigned char f2:3;
	unsigned char f3:5;	// crossing 1byte limit hence 2nd byte will be allocated
};

int main(void)
{
	printf("Size of strcut bits1 is : %d\n", sizeof(struct bits1));
	printf("Size of strcut bits2 is : %d\n", sizeof(struct bits2));
	printf("Size of strcut bits3 is : %d\n", sizeof(struct bits3));


	return(0);
}

