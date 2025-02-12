#include <stdio.h>

int add(int arr[10])
{
	int sum = 0;
	printf("Size of arr is %ld\n", sizeof(arr));
	
	// Sizeof in this function context will be the size of integer pointer and
	// not the sizeof array, because whenever we will pass array to function
	// it will be treated as pointer and not an array
	
	for (int i = 0; i < sizeof(arr); i++)
		sum += arr[i];

	return(sum);
}

int main(void)
{
	int a[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	printf("Size of a is %ld\n", sizeof(a));

	printf("sum = %d\n", add(a));

	return(0);
}
