// #include "apue.h"
// #include <pthread.h>
#include <stdio.h>
#include <unistd.h>


extern int makethread(void *(*fn)(void *), void *arg);

void *task1(void *arg)
{
	while (1) {
	
		printf("miao miao!\n");
	
		sleep(1);
	}

	return NULL;
}



int main(void)
{
	int err;

	err = makethread(task1, NULL);

	printf("errno: %d\n", err);

	sleep(10);

	return 0;
}
