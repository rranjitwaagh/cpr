#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define CHILD 0

int main(void)
{
	pid_t pid;

	pid = fork();

	printf("current PID = %d\n", getpid());

	getchar();

	if (pid == CHILD) { 
		printf("Child: My PID is %d\n", getpid());
		while(1);
	} else { 
		printf("My PID is %d\n", getpid());
		printf("Child PID is %d\n", pid);
	}

	return(0);
}
