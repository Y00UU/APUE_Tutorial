#include "apue.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;

	TELL_WAIT();
	
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	}
	else if (pid > 0) { //parent
		//printf("Hi Child!\n");
		printf("P:Hi Child!");
		fflush(stdout);
		TELL_CHILD(pid);
		WAIT_CHILD();
		//printf("God Bye Child!\n");
		printf("P:God Bye Child!");
		fflush(stdout);

		if (waitpid(pid, NULL, 0) < 0)
			err_sys("waitpid error");
	}
	else { //child
		WAIT_PARENT();
		//printf("Hello Parent!\n");
		printf("C:Hello Parent!");
		fflush(stdout);
		TELL_PARENT(getppid());
		sleep(1);
	}

	exit(0);
}
