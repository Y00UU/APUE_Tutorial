#include "apue.h"
#include "slock.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define CNT	(1000000)

static int num;
static struct slock *sp;

void *thd_fn1(void *arg)
{
	static int is_exit = 0;
	
	printf("thd_fn1\n");
	while (is_exit == 0) {
		if (num % 2 == 0) sleep(1);
		s_lock(sp);
		printf("[1]:%d\n", ++num);
		fflush(stdout);
		is_exit = num >= CNT ? 1 : 0;
		s_unlock(sp);
	}

	return NULL;
}

void *thd_fn2(void *arg)
{
	static int is_exit = 0;

	printf("thd_fn2\n");
	while (is_exit == 0) {
		if (s_trylock(sp) == 0){
			printf("[2]:%d\n", ++num);
			fflush(stdout);
			is_exit = num >= CNT ? 1 : 0;
			s_unlock(sp);
		}
	}
	return NULL;
}

int main(void)
{
	pthread_t tid1, tid2;

	if (pthread_create(&tid1, NULL, thd_fn1, NULL) != 0)
		err_sys("pthread create thd_fn1 error");
	if (pthread_create(&tid2, NULL, thd_fn2, NULL) != 0)
		err_sys("pthread create th_fn2 error");
	
	if ((sp = s_alloc()) == NULL)
		err_sys("s_alloc error");

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	s_free(sp);

	exit(0);
}
