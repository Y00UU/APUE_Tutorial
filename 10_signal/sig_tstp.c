#include "apue.h"


#define BUFFSIZE 1024


static void sig_tstp(int signo) {

	sigset_t mask;

	printf("in sig_tstp\n");

	sigemptyset(&mask);
	sigaddset(&mask, SIGTSTP);
	sigprocmask(SIG_UNBLOCK, &mask, NULL);

	signal(SIGTSTP, SIG_DFL);

	kill(getpid(), SIGTSTP);

	printf("kill ret\n");

	signal(SIGTSTP, sig_tstp);
}

static void sig_cont(int signo) {

	printf("proc(%ld) continue\n", (long int)getpid());
}



int main(void) {

	int n;
	char buf[BUFFSIZE];


	if (signal(SIGTSTP, SIG_IGN) == SIG_DFL) {
		signal(SIGTSTP, sig_tstp);
		printf("SIGTSTP -> sig_tstp\n");
	}

	if (signal(SIGCONT, sig_cont) == SIG_ERR)
		err_sys("signal (SIGCONT) error");

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");

	if (n < 0)
		err_sys("read error");

	exit(0);
}
