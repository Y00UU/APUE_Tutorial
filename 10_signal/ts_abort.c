#include "apue.h"
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

extern void abort(void);
extern void pr_exit(int);

static void sig_alrm(int signo) {

	printf("read time out, abort proc\n");

	abort();
}

static void sig_abrt(int signo) {
	
	printf("proc abort\n");
	
}

int main(void) {
	
	pid_t pid;
	int n, status;
	char buf[MAXLINE];

	printf("input at 5s time...\n");

	signal(SIGALRM, sig_alrm);
	signal(SIGABRT, sig_abrt);
	
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	}
	else if (pid == 0) {
		alarm(5);
		if ((n = read(STDIN_FILENO, buf, MAXLINE)) < 0)
			err_sys("read error");
		alarm(0);
		exit(0);
	}

	if ((pid = waitpid(pid, &status, 0)) < 0)
		err_sys("waitpid error");
	
	pr_exit(status);

	write(STDOUT_FILENO, buf, n);

	printf("grpgram ending\n");
	exit(0);
}


