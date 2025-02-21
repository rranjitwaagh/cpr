#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define CHILD 0

int main(void)
{
	pid_t pid;

	pid = fork();

	printf("current PID = %d\n", getpid());

	if (pid == CHILD) { 
		printf("Child: My PID is %d\n", getpid());
		getchar();
	} else { 
		printf("My PID is %d\n", getpid());
		printf("Child PID is %d\n", pid);
		while(1);
	}

	return(0);
}
