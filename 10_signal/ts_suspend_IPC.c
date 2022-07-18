#include "apue.h"
#include "suspend_IPC.h"
#include <unistd.h>


static void charatatime(char *);

/*
static void sig_alrm(int signo) {
	printf("in sig_alrm handler\n");
}
*/



int main(void) {

	pid_t pid;

	// signal(SIGALRM, sig_alrm);

	TELL_WAIT();

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	}
	else if (pid == 0) {
		// WAIT_PARENT();
		charatatime("output from child\n");
		TELL_PARENT(getppid());
		// alarm(5);
		// pause();
		// alarm(0);
	}
	else {
		WAIT_CHILD();
		charatatime("output from parent\n");
		// TELL_CHILD(pid);
	}
	exit(0);
}


static void charatatime(char *str) {

	char *ptr;
	int c;

	ptr = str;
	setbuf(stdout, NULL);

	while ((c = *ptr++) != '\0')	
		putc(c, stdout);
}
