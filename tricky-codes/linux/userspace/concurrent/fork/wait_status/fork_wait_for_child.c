#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#define CHILD 0

int main(void)
{
	pid_t pid;
	int child_status;
	int k = 10;

	printf("current PID = %d\n", getpid());

	getchar();

	pid = fork();
	if (pid == CHILD) { 
		printf("Child: My PID is %d\n", getpid());
		k = 44;
		printf("End of Child: K is %d\n", k);
		exit(100);
	} else { 
		printf("My PID is %d\n", getpid());
		printf("Child PID is %d\n", pid);
		printf("K is %d\n", k);
		wait(&child_status);	// await process status
		printf("End of parent: K is %d\n", k);
		printf("Chaild status : %d\n", WEXITSTATUS(child_status));
	}

	return(0);
}
