#include "sleep5.h"
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

typedef void Sigfunc(int);

static sigjmp_buf env_alrm;

static void sig_alrm(int signo);



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

	if (last_sec > seconds) {
		last_sec -= seconds;
		alarm(last_sec);
	}
	else
		last_sec = (alarm(0));
	
	return (last_sec);
}



static void sig_alrm(int signo) {
	siglongjmp(env_alrm, 1);
}
