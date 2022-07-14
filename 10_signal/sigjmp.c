#include "apue.h"
#include <setjmp.h>
#include <time.h>


static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjmp;

static void sig_usr1(int);
static void sig_alrm(int);

void pr_mask(const char *);

int main(void) {

	if (signal(SIGUSR1, sig_usr1) < 0)
		err_sys("signal (SIGUSR1) error");

	if (signal(SIGALRM, sig_alrm) < 0)
		err_sys("signal (SIGALRM) error");

	
	pr_mask("starting main: ");

	if (sigsetjmp(jmpbuf, 1)) {
	
		pr_mask("ending main: ");
	
		exit(0);
	}

	canjmp = 1;
	
	while (1)
		pause();
}


static void sig_usr1(int signo) {
	time_t starttime;

	if (canjmp == 0)
		return ;

	pr_mask("starting sig_usr1: ");

	alarm(3);
	starttime = time(NULL);
	while (1)
		if (time(NULL) > starttime + 5)
			break;

	pr_mask("finishing sig_usr1: ");

	canjmp = 0;
	siglongjmp(jmpbuf, 1);
}

static void sig_alrm(int signo) {
	pr_mask("in sig_alrm: ");
}
