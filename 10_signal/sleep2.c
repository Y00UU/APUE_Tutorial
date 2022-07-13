#include "sleep2.h"
#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void Sigfunc(int);

static jmp_buf env_alrm;

static void sig_alrm(int signo);




static void sig_alrm(int signo) {

	longjmp(env_alrm, 1);
}

unsigned int sleep2(unsigned int seconds) {

	Sigfunc *sigfunc;
	unsigned int last_sec;

	if ((sigfunc = signal(SIGALRM, sig_alrm)) == SIG_ERR)
		return (seconds);


	if (setjmp(env_alrm) == 0) {

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
		alarm(last_sec);

	return (alarm(0));
}
