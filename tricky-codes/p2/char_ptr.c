#include <stdio.h>

int main(void)
{
	char *c = "RAW";
	*c = 'A';
	printf("c = %c\n", *c);

	return(0);
}

/*
 * Explanation:
 *
 * what is sement fault:
 * 	One of the segments of the program is illegally accessed
 *
 * what is core dump?
 * 	memory snapshot of your process which got killed because of illegal access
 * 	to the memory
 *
 *
 * char *c = "RAW"; 
 *
 * c is pointing to the piece of memory where :
 * c ------> "RAW" i.e. R A W \0
 * c is pointing to a constant string: which means that the 4 bytes of memory are marked as READ-ONLY
 * now when we do *c = 'A', we are basically trying to write onto the memory which is READ-ONLY
 */
 
