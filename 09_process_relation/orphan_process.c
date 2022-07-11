#include "apue.h"
#include <errno.h>

static void sig_hup(int signo) {

	printf("SIGHUB receievd, signo = %d, pid = %ld\n", signo, (long int) getpid());
}


static void pr_ids(const char *name) {

	printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n",
			name, (long int) getpid(), (long int) getppid(), (long int) getpgrp(), (long int)tcgetpgrp(STDIN_FILENO));
	
	fflush(stdout);
}

int main(void) {
	
	char c;
	pid_t pid;



	pr_ids("parent");
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	}
	else if (pid > 0) {
		sleep(5);
	}
	else {
		pr_ids("child");
		fputs("child ready SIGHUB\n", stdout);
		signal(SIGHUP, sig_hup);
		fputs("child ready SIGTSTP\n", stdout);
		kill(getpid(), SIGTSTP);
		pr_ids("child");
		if (read(STDIN_FILENO, &c, 1) != 1)
			printf("read error %d on controlling TTY\n", errno);
	}


	exit(0);
}
