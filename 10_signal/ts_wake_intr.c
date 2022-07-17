#include "apue.h"
#include <unistd.h>

unsigned int sleep5(unsigned int);

static void sig_int(int);


int main(void) {


	unsigned int unslept;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");

	//unslept = sleep(5);
	
	unslept = sleep5(5);

	printf("sleep retruned: %u\n", unslept);

	exit(0);
}

static void sig_int(int signo) {
	
	int i, j;
	volatile int k;

	printf("\nsig_int starting\n");

	for (i = 0; i < 300000; ++i)
		for (j = 0; j < 4000; ++j)
			k += i * j;
	printf("sig_int finished, i = %d, j = %d\n", i, j);
}	
