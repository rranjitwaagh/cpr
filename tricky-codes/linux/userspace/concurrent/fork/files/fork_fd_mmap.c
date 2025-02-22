#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define CHILD 0

int main(void)
{
	pid_t pid;
	int fd = -1, size = 4096, status;
	char *area;

	// map some area to be shared between child and parent
	area = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, fd, 0);

	pid = fork();

	if (pid == CHILD) {
		strcpy(area, "This is message from child");
		printf("Child has written : %s\n", area);
		exit(EXIT_SUCCESS);
	} else {
		wait(&status);
		printf("Parent has read :%s\n", area);
		exit(EXIT_SUCCESS);
	}

	return(0);
}

