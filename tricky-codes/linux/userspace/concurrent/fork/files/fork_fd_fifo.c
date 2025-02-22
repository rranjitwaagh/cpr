#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define FIFO_NAME "/tmp/myfifo"

#define DEATH(mess) { perror(mess); exit(errno); }

#define CHILD 0

int main(void)
{
	pid_t pid;
	int fd;
	char message[] = "Hello World on FIFO";

	if (mkfifo(FIFO_NAME, 0666) < 0)
		DEATH(FIFO_NAME);
	printf("FIFO %s created\n", FIFO_NAME);

	fflush(stdout);
	pid = fork();

	if (pid == CHILD) {
		fd = open(FIFO_NAME, O_WRONLY);
		printf("The child is sending: %s\n", message);

		if (write(fd, message, sizeof(message)) < 0)
			DEATH("write error from child to fifo");

		close(fd);
		exit(EXIT_SUCCESS);
	} else {
		fd = open(FIFO_NAME, O_RDONLY);
		if (read(fd, message, sizeof(message)) < 0)
			DEATH("read error in parent from fifo");
		printf("The parent received : %s\n", message);
		close(fd);

		if (unlink(FIFO_NAME))
			DEATH("Had trouble removing FIFO");

		exit(EXIT_SUCCESS);
	}
	return(0);
}

