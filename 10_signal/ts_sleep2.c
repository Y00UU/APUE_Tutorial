#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void Sigfunc(int);

static jmp_buf env_alrm;


static void sig_alrm(int signo) {

	longjmp(env_alrm, 1);
}


static void sig_alrm_tmp(int signo) {

	printf("sig_alrm_tmp: %d\n", signo);
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


int main(int argc, const char *argv[]) {
	
	unsigned int sleep_time;

	if (argc != 3) {
		printf("usage: ./a.out [seconds1] [seconds2]");
		return (0);
	}	
	else {
		signal(SIGALRM, sig_alrm_tmp);
		alarm(atoi(argv[1]));
		sleep_time = atoi(argv[2]);
	}

	printf("proc(%ld) sleep %us...\n", (long int)getpid(), sleep_time);
	
	sleep2(sleep_time);
	
	printf("proc(%ld) wake up\n", (long int)getpid());

	return 0;
}
