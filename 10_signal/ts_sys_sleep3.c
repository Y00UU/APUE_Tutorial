#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void sig_sleep_handler(int signo) {
	printf("in sig_sleep_handler ret\n");
}

static unsigned int my_sleep(unsigned int seconds) {
	struct sigaction newact, oldact;
	sigset_t newmask, oldmask, suspendmask;
	unsigned int unslept, last_slept;

	newact.sa_handler = sig_sleep_handler;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGALRM, &newact, &oldact);

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGALRM);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);

	last_slept = alarm(seconds);
	if (seconds > last_slept)
		alarm(last_slept);

	suspendmask = oldmask;

	sigdelset(&suspendmask, SIGALRM);
	
	sigsuspend(&suspendmask);



	sigaction(SIGALRM, &oldact, NULL);
	
	sigprocmask(SIG_SETMASK, &oldmask, NULL);

	unslept = alarm(0);
	if (last_slept > seconds) {
		last_slept -= seconds;
	}
	else {
		unslept = seconds-last_slept+unslept;
		last_slept = 0;
	}

	if (last_slept > 0)	
		alarm(unslept+last_slept);
	else
		alarm(0);

	return (unslept);
}

static void sig_alrm(int signo) {
	printf("in sig_alrm handler ret\n");
}

static void sig_usr1(int signo) {
	printf("in sig_uar1 handler ret\n");
}


int main(void) {

	unsigned int unslept = 20, alrm_sec = 30;

	int i, j;
	volatile int k;

	signal(SIGALRM, sig_alrm);
	signal(SIGUSR1, sig_usr1);

	alarm(alrm_sec);

	printf("sleep %us...\n", unslept);
	unslept = my_sleep(unslept);
	
	printf("wake up, unslept = %u\n", unslept);

	for (i = 0; i < 800000; ++i)
		for (j = 0; j < 10000; ++j)
			k += i * j;
	
	printf("ending proc\n");

	return 0;
}
