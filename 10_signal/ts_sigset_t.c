#if defined(USAGE_SYS_SIGSET)
#include <signal.h>

#elif defined(USAGE_DEMO_SIGSET)
#include "signal_set.h"

#else
#include <signal.h>

#endif

#include <stdio.h>


#define PR_SIG(set, signo) pr_signal(#signo, signo, sigismember(set, signo))




static void pr_signal(char *name, int signo, int status) {

	printf("%s(%d): %d\n", name, signo, status);
}




int main(void) {

	sigset_t set;


#if defined(USAGE_SYS_SIGSET)
	printf("usage system sigset_t\n");

#elif defined(USAGE_DEMO_SIGSET)
	printf("usage demo sigset_t\n");

#else
	printf("usage default sigset_t\n");

#endif

	

	sigemptyset(&set);
	PR_SIG(&set, SIGALRM);

	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGCHLD);
	sigaddset(&set, SIGKILL);
	sigaddset(&set, SIGSTOP);

	PR_SIG(&set, SIGUSR1);
	PR_SIG(&set, SIGINT);
	PR_SIG(&set, SIGALRM);
	PR_SIG(&set, SIGKILL);

	sigdelset(&set, SIGUSR1);	
	PR_SIG(&set, SIGUSR1);

	sigaddset(&set, SIGALRM);
	PR_SIG(&set, SIGALRM);

	sigfillset(&set);
	PR_SIG(&set, SIGUSR1);

	return (0);
}
