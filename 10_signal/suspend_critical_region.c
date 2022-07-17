#include "apue.h"
#include <unistd.h>


extern void pr_mask(const char *);


static void sig_int(int signo) {
	pr_mask("in sig_int: ");
}



int main(void) {

	sigset_t newmask, oldmask, waitmask;

	pr_mask("program start: ");

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");

	sigemptyset(&waitmask);
	sigaddset(&waitmask, SIGUSR1);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);


	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");

	printf("The SIGINT is blocked. sleep 5s, can key ctrl+c try to interrupt it\n");
	sleep(5);
	printf("wake up\n");
	

	pr_mask("in critical region: ");

	printf("unblock SIGINT, SIGUSR1 is block. key ctrl+c to recovery interrupt signal\n");
	if (sigsuspend(&waitmask) != -1)
		err_sys("sigsuspend is error");

	pr_mask("after return from sigsuspend: ");

	
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");

	pr_mask("program exit: ");

	exit(0);
}
