#include <stdio.h>
#include <signal.h>
#include <unistd.h>


static void sig_alrm(int signo) {
	printf("sig_alrm: signo = %d\n", signo);
}


unsigned int sleep1(unsigned int seconds) {

	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return (seconds);

	alarm(seconds);
	pause();
	return (alarm(0));
}


int main(void) {

	int sleep_t = 5;

	printf("start sleep1 %ds...\n", sleep_t);

	sleep1(sleep_t);
	
	printf("wake up\n");

	return (0);
}
