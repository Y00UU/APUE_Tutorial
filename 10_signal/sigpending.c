#include "apue.h"
#include <signal.h>

static void sig_quit(int);


int main(void) {

	sigset_t newmask, oldmask, pendmask;


	if (signal(SIGQUIT, sig_quit) < 0)
		err_sys("signal quit error");

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");

	printf("sleep 10s..\n");
	sleep(10);

	if (sigpending(&pendmask) < 0)
		err_sys("sigpending error");

	if (sigismember(&pendmask, SIGQUIT))
		printf("\nSIGQUIT pending\n");


	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");

	printf("SIGQUIT unblock\n");

	printf("sleep 5s..\n");
	sleep(5);

	exit(0);
}

static void sig_quit(int signo) {

	printf("caught SIGQUIT\n");

	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("can't reset SIGQUIT");
}
