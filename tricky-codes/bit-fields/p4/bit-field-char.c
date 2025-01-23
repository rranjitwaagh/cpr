#include <stdio.h>

struct bits {
	char	f1:1,
		f2:2,
		f3:3;
};

int main(void)
{
	struct bits b;

	b.f1 = 1;
	b.f2 = 2;
	b.f3 = 5;

	printf("f1:%d\tf2:%d\tf3:%d\n", b.f1, b.f2, b.f3);
	//printf("f1:%p\tf2:%p\tf3:%p\n", &b.f1, &b.f2, &b.f3);
	printf("Size of strcut bits is : %d\n", sizeof(struct bits));


	return(0);
}

