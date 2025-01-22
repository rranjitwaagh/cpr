#include <stdio.h>

int main(void)
{
	union un {
		short val;
		char ch;
	};

	union un u;

	u.val = 258;
	printf("Before u.val 	= %d\n", u.val);
	u.ch = 1;

	printf("u.val 	= %d\n", u.val);
	printf("u.ch 	= %d\n", u.ch);

	return(0);
}

/*
 	u.val = 258; // HEX = 0x0102
	Memory -------------> | 02 | 01 |
	
	u.ch = 1
	Memory -------------> | 01 | 01 | ---> 0x0101 = 257

	After u.ch the same starting memory location value will be updated to 0x01 from 0x02
	Hence the output comes as 257

 */
