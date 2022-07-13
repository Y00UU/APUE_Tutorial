#include "apue.h"
#include <time.h>

#define ALRM_TIMEVAL_SEC	(5)

static void time_alarm(int signo) {

	time_t t = time(NULL);				/* time reentrant function */

	printf("in signal handler\n");

	if (t)
		printf("pid = %ld, current time_t = %u\n", (long int) getpid(), (unsigned int) t); /* getpid reentrant function */
	

	signal(SIGALRM, time_alarm);
	alarm(ALRM_TIMEVAL_SEC);
}


int main(void) {

	signal(SIGALRM, time_alarm);

	printf("start the alarm: %d\n", ALRM_TIMEVAL_SEC);
	alarm(ALRM_TIMEVAL_SEC);

	while (1);
}
