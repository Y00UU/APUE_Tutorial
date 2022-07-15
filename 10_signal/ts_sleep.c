#include <stdio.h>
#include <unistd.h>
#include <signal.h>

unsigned int sleep5(unsigned int);

static void sig_alrm(int signo) {
	printf("in sig_alrm handler\n");
}

int main(void) {


	const int s1 = 10, s2 = 10, s3 = 15;

	signal(SIGALRM, sig_alrm);
	
	alarm(5);
	printf("sleep %ds...\n", s1);
	sleep(s1);
	printf("wake up\n");
	

	alarm(15);
	printf("sleep5 %ds...\n", s2);
	sleep5(s2);
	printf("wake up\n");

	
	printf("sleep %ds...\n", s3);
	sleep(s3);
	printf("wake up\n");

	return 0;
}
