#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_routine(void *p)
{
	printf("Thread Hello World\n");
}

int main(void)
{
	pthread_t thread;
	int rv;

	rv = pthread_create(&thread, NULL, thread_routine, NULL);

	if (rv)
		printf("Failed to create thread\n");

	pthread_exit(NULL);
	return(0);
}
