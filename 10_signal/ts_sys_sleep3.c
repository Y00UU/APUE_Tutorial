#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void sig_sleep_handler(int signo) {
	printf("in sig_sleep_handler ret\n");
}

static unsigned int my_sleep(unsigned int seconds) {
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

	unslept = alarm(seconds);
	if (seconds > unslept)
		alarm(unslept);

	suspendmask = oldmask;

	sigdelset(&suspendmask, SIGALRM);
	
	sigsuspend(&suspendmask);
	
	if (seconds < unslept)
		unslept -= seconds;
	else
		unslept = alarm(0);
	
	sigaction(SIGALRM, &oldact, NULL);
	
	sigprocmask(SIG_SETMASK, &oldmask, NULL);
	
	alarm(unslept);

	return (unslept);
}

static void sig_alrm(int signo) {
	printf("in sig_alrm handler ret\n");
}


int main(void) {

	unsigned int unslept = 5, alrm_sec = 10;

	int i, j;
	volatile int k;

	signal(SIGALRM, sig_alrm);
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
