#include "apue.h"
#include <sys/wait.h>

static int cnt = 0;

int main(void) {


	char buf[MAXLINE];

	pid_t pid = -1;

	int status = -1;

	printf("%%(%d) ", cnt);
	
	printf("0 pid: %ld, %s\n", (long int)pid,  buf);

	while (fgets(buf, MAXLINE, stdin) != NULL) {

		if (buf[strlen(buf)-1] == '\n')
			buf[strlen(buf)-1] = '\0';

		++cnt;

		printf("1 pid: %ld, %s\n", (long int)pid,  buf);

		
		pid = fork();

		printf("fork: %ld\n", (long int) pid);

		if (pid < 0)	
			err_sys("fork error");

		/*
		if ((pid = fork()) < 0) {
			err_sys("fork error");
		}
		*/
		else if (pid == 0) {
			printf("execute: %s\n", buf);
			execlp(buf, buf, (char *) 0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		
		printf("2 pid: %ld, %s\n", (long int)pid,  buf);

		if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		
		printf("3 pid: %ld, %s\n", (long int)pid,  buf);
		
		printf("%%(%d) ", cnt);
	}


	exit(0);
}
