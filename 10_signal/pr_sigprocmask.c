#include "pr_sigprocmask.h"
#include <signal.h>
#include <errno.h>
#include <stdio.h>


void pr_mask(const char *str) {

	sigset_t sigset;
	int errno_save;

	errno_save = errno;

	if (sigprocmask(0, NULL, &sigset) < 0) {
		printf("sigprocmask error\n");
	}
	else {
	
		printf("%s", str);

		if (sigismember(&sigset, SIGINT))
			printf(" SIGINT");

		if (sigismember(&sigset, SIGQUIT))
			printf(" SIGQUIT");

		if (sigismember(&sigset, SIGUSR1))
			printf(" SIGUSR1");

		if (sigismember(&sigset, SIGUSR2))
			printf(" SIGUSR2");


		if (sigismember(&sigset, SIGALRM))
			printf(" SIGALRM");
		

		printf("\n");
	}

	errno = errno_save;
}
