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
	
	unsigned int sleep_time;
	int i, j;
	volatile int k = 0;

	if (argc != 3) {
		printf("usage: ./a.out [seconds1] [seconds2]\n");
		return (0);
	}	
	else {
		signal(SIGALRM, sig_alrm_tmp);
		alarm(atoi(argv[1]));
		sleep_time = atoi(argv[2]);
	}

	printf("proc(%ld) sleep %us...\n", (long int)getpid(), sleep_time);
	
	sleep5(sleep_time);
	// sleep(sleep_time);
	
	printf("proc(%ld) wake up\n", (long int)getpid());

	for (i = 0; i < 600000; ++i)
		for (j = 0; j < 8000; ++j)
			k += i * j;
	
	pr_mask("ending sigprocmask: ");
	
	return 0;
}







static void sig_alrm(int signo) {
	siglongjmp(env_alrm, 1);
}

unsigned int sleep5(unsigned int seconds) {

	Sigfunc *sigfunc;
	unsigned int last_sec;

	if ((sigfunc = signal(SIGALRM, sig_alrm)) == SIG_ERR)
		return (seconds);


	if (sigsetjmp(env_alrm, 1) == 0) {

		last_sec = alarm(seconds);

		if (last_sec > 0 && last_sec <= seconds) {
				
			if (signal(SIGALRM, sigfunc) == SIG_ERR)
				return (last_sec);
		
			alarm(last_sec);		
		}

		pause();	
	}

	signal(SIGALRM, sigfunc);

	if (last_sec > seconds)
		last_sec = alarm(last_sec-seconds);
	else
		last_sec = (alarm(0));
	
	return (last_sec);
}
