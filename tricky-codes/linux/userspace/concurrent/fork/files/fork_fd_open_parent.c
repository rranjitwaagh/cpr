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
	char buf[2] = {};

	pid = fork();

	if (pid == CHILD) {
		read(fd, buf, 2); // No FD opened prior to fork call, child is not having any open file descriptor currently
		printf("Child: buf[0]:%c, buf[1]:%c\n", buf[0], buf[1]);
		close(fd);	// This will cause COW
	} else {
		fd = open("./test", O_RDONLY);	// FD is opened in parent process
		wait(&childstatus);
		read(fd, buf, 2);
		printf("Parent: buf[0]:%c, buf[1]:%c\n", buf[0], buf[1]);
		close(fd);
	}

	return(0);
}

