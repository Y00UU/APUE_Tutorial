#include <signal.h>
#include <unistd.h>
#include <stdio.h>


static void sig_alrm(int signo) {
	printf("in sig_alrm handler ret\n");
}


int main(void) {

	unsigned int unslept = 10, alrm_sec = 5;
	int i, j;
	volatile int k;

	signal(SIGALRM, sig_alrm);
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
