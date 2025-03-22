#include <stdio.h>

int main(void)
{
	int a  = 1;
	unsigned int b = 1;

	printf("a is %d, 0x%x\n", a, a);
	printf("b is %d, 0x%x\n", b, b);

	// Right shift on signed values will be impacted by 2's complement
	// Arithmetic RIGHT SHIFT will be applied preserving the sign bit (msb)
	printf("((a << 31) >> 4) is signed %d, 0x%x\n", ((a << 31) >> 4), ((a << 31) >> 4));

	// Right shift on unsigned values willnot be impacted by 2's complement
	// as Logical Right Shift will be applied here and msb will have value and not sign
	printf("((b << 31) >> 4) is unsigned %d, 0x%x\n", ((b << 31) >> 4), ((b << 31) >> 4));

	return(0);
}
