#include <stdio.h>
#include <string.h>

int main()
{
	char ch[] = { 'R', 'A', 'N', 'J', 'I', 'T', 'W', 'A', 'G', 'H' };
	char comp[] = { "RANJITWAGH" };	// this is STRING
	
	printf("strlen(%s) is %d\n", ch, strlen(ch));
	printf("strlen(%s) is %d\n", comp, strlen(comp));
	printf("Sizeof(%s) is %d\n", ch, sizeof(ch));
	printf("Sizeof(%s) is %d\n", comp, sizeof(comp));

	return(0);
}
