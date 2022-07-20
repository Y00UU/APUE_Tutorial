#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void sig_sleep_handler(int signo) {
	printf("in sig_sleep_handler ret\n");
}

static unsigned int my_sleep(unsigned int slp_sec) {
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

static void sig_alrm(int signo) {
	printf("in sig_alrm handler ret\n");
}

static void sig_usr1(int signo) {
	printf("in sig_uar1 handler ret\n");
}


int main(int argc, const char *argv[]) {

	unsigned int unslept, alrm_sec;

	int i, j;
	volatile int k;

	sigset_t zeromask;

	if (argc != 3) {
		printf("usage: ./a.out t1 t2\n");
		return 1;
	}
	
	alrm_sec = atoi(argv[1]);
	unslept = atoi(argv[2]);

	signal(SIGALRM, sig_alrm);
	signal(SIGUSR1, sig_usr1);

	alarm(alrm_sec);

	printf("sleep %us...\n", unslept);
	unslept = my_sleep(unslept);
	printf("wake up, unslept = %u\n", unslept);
	
	printf("wait the alarm signal: ");
	fflush(stdout);
	sigemptyset(&zeromask);
	sigsuspend(&zeromask);
	printf("program ending\n");

	return 0;
}
