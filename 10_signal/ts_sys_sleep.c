#include <signal.h>
#include <unistd.h>
#include <stdio.h>


static void sig_alrm(int signo) {
	printf("in sig_alrm handler ret\n");
}

static void sig_usr1(int signo) {
	printf("in sig_uar1 handler ret\n");
}


int main(void) {

	unsigned int unslept = 25, alrm_sec = 15;
	int i, j;
	volatile int k;

	signal(SIGALRM, sig_alrm);
	signal(SIGUSR1, sig_usr1);

	alarm(alrm_sec);

	printf("sleep %us...\n", unslept);
	unslept = sleep(unslept);
	
	printf("wake up, unslept = %u\n", unslept);

	for (i = 0; i < 300000; ++i)
		for (j = 0; i < 4000; ++j)
			k += i * j;

	printf("ending proc\n");

	return 0;
}
