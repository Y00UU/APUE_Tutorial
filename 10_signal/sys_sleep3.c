#include <signal.h>
#include <unistd.h>
#include <stdio.h>
static void sig_sleep_handler(int signo) {
	printf("in sig_sleep_handler ret\n");
}

unsigned int sys_sleep3(unsigned int slp_sec) {
	struct sigaction newact, oldact;
	sigset_t newmask, oldmask, suspendmask;
	unsigned int unslp_sec, alrm_sec;

	newact.sa_handler = sig_sleep_handler;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGALRM);

	sigprocmask(SIG_BLOCK, &newmask, &oldmask);
	sigaction(SIGALRM, &newact, &oldact);

	alrm_sec = alarm(slp_sec);
	if (alrm_sec > 0 && alrm_sec < slp_sec) {
		sigaction(SIGALRM, &oldact, NULL);
		alarm(alrm_sec);
	}
	suspendmask = oldmask;
	sigdelset(&suspendmask, SIGALRM);
	sigsuspend(&suspendmask);

	sigaction(SIGALRM, &oldact, NULL);
	sigprocmask(SIG_SETMASK, &oldmask, NULL);

	unslp_sec = alarm(0);
	
	if (alrm_sec > 0 && alrm_sec < slp_sec) {
		if (unslp_sec > 0) {
			alarm(unslp_sec);
			unslp_sec = slp_sec-(alrm_sec-unslp_sec);
		}
		else {
			alarm(0);
			unslp_sec = slp_sec-alrm_sec;
		}
	}
	else {
		alarm(alrm_sec-(slp_sec-unslp_sec));
	}
	
	return (unslp_sec);
}

