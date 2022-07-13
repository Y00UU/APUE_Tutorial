#include "apue.h"
#include <sys/wait.h>


static void sig_cld(int);



int main(void) {

	pid_t pid;


	if (signal(SIGCLD, sig_cld) == SIG_ERR)
		perror("signal error");

	if ((pid = fork()) < 0) {
	
		perror("fork error");
	}
	else if (pid == 0) {
		sleep(2);
		_exit(0);
	}

	printf("parent pid = %ld\n", (long int) getpid());

	pause();

	exit(0);
}


static void sig_cld(int signo) {

	pid_t pid;

	int status;

	printf("SIGCLD received\n");

	signal(SIGCLD, sig_cld);

	if (signal(SIGCLD, sig_cld) == SIG_ERR)
		perror("signal error");
	if ((pid = wait(&status)) < 0)
		perror("wait error");

	printf("parent pid = %ld, child pid = %ld\n", (long int)getpid() ,(long int)pid);
}	
