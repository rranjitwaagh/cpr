#include <stdio.h>

struct bits {
	unsigned char	f1:1,
			r1:1,
			f2:2,
			r2:1,
			f3:3;
};

int main(void)
{
	struct bits b;

	b.f1 = 1;
	b.f2 = 3;
	b.f3 = 7;

	printf("f1:%d\tf2:%d\tf3:%d\n", b.f1, b.f2, b.f3);
	//printf("f1:%p\tf2:%p\tf3:%p\n", &b.f1, &b.f2, &b.f3);
	printf("Size of strcut bits is : %d\n", sizeof(struct bits));


	return(0);
}

