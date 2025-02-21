#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#define CHILD 0

int global = 99; // = 10;

int main(void)
{
	pid_t pid;
	int child_status;

	printf("Initial: global = %d\n", global);

	pid = fork();
	// After the fork() call all code will be executed in both parent and child context
	global = 1;

	if (pid == CHILD) { 
		global = 10;
		printf("Child: global = %d\n", global);
	} else { 
		wait(&child_status);	// await process status
		printf("Parent: global = %d\n", global);
	}

	return(0);
}
