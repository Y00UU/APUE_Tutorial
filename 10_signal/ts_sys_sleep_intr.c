#include "apue.h"

//#define SYS_SLP2
//#define SYS_SLP3

#ifdef SYS_SLP2
extern unsigned int sys_sleep2(unsigned int);

#elif SYS_SLP3
extern unsigned int sys_sleep3(unsigned int);

#else
#include <unistd.h>

#endif


static void sig_int(int);


int main(void) {


	unsigned int unslept;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");

	unslept = 
#if defined(SYS_SLP2)
	sys_sleep2(5);
#elif defined(SYS_SLP3)
	sys_sleep3(5);
#else
	sleep(5);
#endif
	printf("sys_sleep retruned: %u\n", unslept);

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
