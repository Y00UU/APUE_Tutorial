#include <signal.h>
#include <stdio.h>
#include <unistd.h>

typedef void Sigfunc(int);

Sigfunc *signal_intr(int, Sigfunc *);


static void sig_alrm(int signo) {
	printf("signal alarm\n");
}


int main(void) {


	if (signal_intr(SIGALRM, sig_alrm) < 0)
		printf("my_signal error\n");
	
	printf("sleep 5s...\n");
	alarm(5);
	pause();	
	printf("wake up\n");

	return 0;
}
