#include <stdio.h>

int main()
{

    int arr[5] = { 1, 2, 3, 4, 5 };

    // Find the size of array arr
    // 1. Using pointer
    int n = *(&arr + 1) - arr;

    // 2. normal way
    // int n = sizeof(arr) / sizeof(arr[0]);

    //3. Error
    // int n = sizeof(arr[]) / sizeof(arr[0]);

    printf( "%d", n);
    return 0;
}
