#include <stdio.h>

int main(void)
{
	char c;
	printf("%d\n", c = 128);
	return(0);
}

/**
 What is happening ?

 As this is char data type the MSB(most significant bit) will store the 'sign' information in binary represenataion:

 128 = (MSB) 1000 0000(LSB)

 How is the -ve value processed and stored ?

 1. Take the absolute value of the given number
 => -128 = abs(-128) = 128

 2. Take the binary representation of number = 128 = 1000 0000

 3. Take 1's complement
 	1000 0000
	0111 1111

 4. Add 1 to the 1's complement
 	0111 1111
       +0000 0001
       --------------
        1000 0000

  As thew MSB is set then this number is (-ve), hence the Negative number (-128) will be stored

 **/

 
 
