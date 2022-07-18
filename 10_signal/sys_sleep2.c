#include <signal.h>
#include <unistd.h>
#include <stdio.h>
static void sig_sleep_handler(int signo) {
	printf("in sig_sleep_handler ret\n");
}

unsigned int sys_sleep2(unsigned int seconds) {
	struct sigaction newact, oldact;
	sigset_t newmask, oldmask, suspendmask;
	unsigned int unslept;

	newact.sa_handler = sig_sleep_handler;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGALRM, &newact, &oldact);

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGALRM);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);

	alarm(seconds);
	suspendmask = oldmask;

	sigdelset(&suspendmask, SIGALRM);
	
	sigsuspend(&suspendmask);
	
	unslept = alarm(0);
	
	sigaction(SIGALRM, &oldact, NULL);
	
	sigprocmask(SIG_SETMASK, &oldmask, NULL);

	return (unslept);
}

