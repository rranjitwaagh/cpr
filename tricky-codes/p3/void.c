#include <stdio.h>

int main(void)
{
	void v, *vp;
	printf("sizeof(v):%d, sizeof(*vp):%d\n", sizeof(v), sizeof(*vp));
	return(0);
}

/**  
gcc void.c
void.c: In function 'main':
void.c:5:7: error: variable or field 'v' declared void
  void v, *vp;

*/
