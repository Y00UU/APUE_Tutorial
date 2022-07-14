#include <signal.h>
#include <stdio.h>
#include <unistd.h>

typedef void Sigfunc(int);



Sigfunc *my_signal(int signo, Sigfunc *func) {

	struct sigaction act, oact;

	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	
	act.sa_flags = 0;
#ifdef SA_INTERRUPT
	act.sa_flags |= SA_INTERRUPT;

#endif
	if (sigaction(signo, &act, &oact) < 0)
		return (SIG_ERR);
	return (oact.sa_handler);
}


static void sig_alrm(int signo) {
	printf("signal alarm\n");
}


int main(void) {


	if (my_signal(SIGALRM, sig_alrm) < 0)
		printf("my_signal error\n");
	
	printf("sleep 5s...\n");
	alarm(5);
	pause();	
	printf("wake up\n");

	return 0;
}
