#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo) {
	
	longjmp(env_alrm, 1);
}

unsigned int sleep3(unsigned int seconds) {

	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return (seconds);

	if (setjmp(env_alrm) == 0) {
		
		alarm(seconds);
		
		pause();
	}

	return (alarm(0));
}


int main(void) {

	printf("sleep 3s...\n");
	sleep3(3);

	printf("sleep 5s..\n");
	sleep3(5);

	return 0;
}
