#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/mman.h>
#define _GNU_SOURCE
#include <linux/sched.h>    /* Definition of struct clone_args */
#include <sched.h>          /* Definition of CLONE_* constants */
#include <sys/syscall.h>    /* Definition of SYS_* constants */
#include <unistd.h>


#define DEATH(mess) { perror(mess); exit(errno); }

#define STACK_SIZE 16000

// global variable
int var;

int do_something(void *arg)
{
	printf("In child process\n");
	var = 40;
	return(0);
}

int main(void)
{
	void *child_Stack;
	var = 10;

	printf("\nValue of var is %d\n", var);

	// get memory for child
	child_Stack = malloc(STACK_SIZE);
	if (child_Stack == NULL)
		DEATH("Malloc error");

	// create a new child
	clone(do_something,
			child_Stack + STACK_SIZE,
			CLONE_VM | CLONE_FILES,
			NULL);

	// sleep to let child update the global variable value
	sleep(1);

	printf("\nValue of var is %d\n", var);
	
	free(child_Stack);

	return(0);
}

