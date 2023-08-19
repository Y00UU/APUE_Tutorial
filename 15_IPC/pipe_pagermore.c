#include "apue.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

#define DEF_PAGER	"/usr/bin/more" //default pager program

int main(int argc, char *argv[])
{
	int n, fd[2];
	pid_t pid;
	char *pager, *argv0;
	char line[MAXLINE];
	FILE *fp;

	if (argc != 2)
		err_quit("usage: a.out <pathname>");
	
	if ((fp = fopen(argv[1], "r")) == NULL)
		err_sys("can't open %s", argv[1]);
	
	if (pipe(fd) < 0)
		err_sys("pipe error");

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	}
	else if (pid > 0) { //parent
		close(fd[0]); //close read end.
		
		//sleep(1);

		// parent copies argv[1] to pipe.
		while (fgets(line, MAXLINE, fp) != NULL) {
			n = strlen(line);
			if (write(fd[1], line, n) != n)
				err_sys("write error to pipe");
			//printf("parent write %d character to pipe\n", n);	
		}
		
		if (ferror(fp) != 0)
			err_sys("fgets error");
		
		// close write end of pipe for reader
		close(fd[1]);

		if (waitpid(pid, NULL, 0) < 0)
			err_sys("waitpid error");

		exit(0);
	}
	else { //child
		//close write end.
		// child process memory only is a copy of parent.
		close(fd[1]);

		//printf("child close fd[1] of write end of pipe.\n");

		if (fd[0] != STDIN_FILENO) {
			if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
				err_sys("dup2 error to stdin");
			
			// don't need this afer dup2
			close(fd[0]);
		}	
	
		// get argumentd for execl().
		if ((pager = getenv("PAGER")) == NULL)
			pager = DEF_PAGER;
		if ((argv0 = strrchr(pager, '/')) != NULL)
			argv0++; //step past rightmost slas.h
		else	
			argv0 = pager; //no slash in pager.

		if (execl(pager, argv0, (char *)0) < 0)
			err_sys("execl error for %s", pager);
	}
	exit(0);
}
