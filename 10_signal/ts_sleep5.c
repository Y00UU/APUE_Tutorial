#include "pr_sigprocmask.h"
#include "sleep5.h"
#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void Sigfunc(int);

static sigjmp_buf env_alrm;

static void sig_alrm(int signo);






static void sig_alrm_tmp(int sigo) {
	printf("in sig_alrm_tep handler\n");
}

int main(int argc, const char *argv[]) {
	
	unsigned int sleep_time1, sleep_time2;
	int i, j;
	volatile int k = 0;

	if (argc != 3) {
		printf("usage: ./a.out [seconds1] [seconds2]\n");
		return (0);
	}	
	else {
		sleep_time1 = atoi(argv[1]);
		sleep_time2 = atoi(argv[2]);
	}

	signal(SIGALRM, sig_alrm_tmp);
	alarm(sleep_time1);
	
	printf("proc(%ld) sleep %us...\n", (long int)getpid(), sleep_time2);
	
	sleep_time2 = sleep5(sleep_time2);
	// sleep(sleep_time);
	
	printf("proc(%ld) wake up\n", (long int)getpid());
/*
	for (i = 0; i < 600000; ++i)
		for (j = 0; j < 8000; ++j)
			k += i * j;
*/

	if (sleep_time2 > 0) {
		sleep5(sleep_time2);
	}
	else
		alarm(0);
	
	pr_mask("ending sigprocmask: ");
	
	return 0;
}

