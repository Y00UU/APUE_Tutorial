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

	alarm(seconds);
	suspendmask = oldmask;

	sigdelset(&suspendmask, SIGALRM);
	
	sigsuspend(&suspendmask);
	
	unslept = alarm(0);
	
	sigaction(SIGALRM, &oldact, NULL);
	
	sigprocmask(SIG_SETMASK, &oldmask, NULL);

	return (unslept);
}

static void sig_alrm(int signo) {
	printf("in sig_alrm handler ret\n");
}


int main(void) {

	unsigned int unslept = 10, alrm_sec = 5;

	signal(SIGALRM, sig_alrm);
	alarm(alrm_sec);

	printf("sleep %us...\n", unslept);
	unslept = my_sleep(unslept);
	
	printf("wake up, unslept = %u\n", unslept);

	return 0;
}
