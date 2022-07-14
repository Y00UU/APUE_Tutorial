#include "apue.h"
#include <setjmp.h>

static jmp_buf env_alrm;

static void sig_alrm(int);


int main(void) {

	int n;

	char line[MAXLINE];

	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_sys("signal(SIGALRM) error");

	if (setjmp(env_alrm) != 0)
		err_quit("read timeout");

	printf("%%input:");
	fflush(stdout);
	alarm(10);
	if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
		err_sys("read error");
	alarm(0);

	write(STDOUT_FILENO, line, n);

	exit(0);
}

static void sig_alrm(int signo) {

	printf("sig_alrm (signo = %d), read I/O is timeout\n", signo);
	
	longjmp(env_alrm, 1);
}
