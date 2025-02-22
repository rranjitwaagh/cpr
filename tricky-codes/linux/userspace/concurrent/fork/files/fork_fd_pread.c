#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CHILD 0

int main(void)
{
	pid_t pid;
	int fd;
	int childstatus;
	char buf[2];

	fd = open("./test", O_RDONLY);	// FD is opened in parent process
	pid = fork();

	if (pid == CHILD) {
		pread(fd, buf, 2, 0); // Child id referring the same opened FD from parent
		printf("Child: buf[0]:%c, buf[1]:%c\n", buf[0], buf[1]);
		close(fd);	// This will cause COW
	} else {
		wait(&childstatus);
		pread(fd, buf, 2, 0);
		printf("Parent: buf[0]:%c, buf[1]:%c\n", buf[0], buf[1]);
		close(fd);
	}

	return(0);
}

