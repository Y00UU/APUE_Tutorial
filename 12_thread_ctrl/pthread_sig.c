#include "apue.h"
#include <pthread.h>
#include <signal.h>

int quitflag;
sigset_t mask;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t waitloc = PTHREAD_COND_INITIALIZER;

void *thr_fn(void *arg)
{
	int err, signo;
	while (1) {
		err = sigwait(&mask, &signo);
		if (err != 0)
			err_exit(err, "sigwait failed");
		switch (signo) {
		case SIGINT:
			printf("\ninterrupt\n");
			break;
		case SIGQUIT:
			printf("\nquit\n");
			pthread_mutex_lock(&lock);
			quitflag = 1;
			pthread_mutex_unlock(&lock);
			pthread_cond_signal(&waitloc);
			return NULL;
		default:
			printf("unexpected signal %d\n", signo);
			exit(1);
		}
	} 
}




int main(void)
{
	int err;
	sigset_t oldmask;
	pthread_t tid;

	sigemptyset(&mask);
	sigaddset(&mask,SIGINT);
	sigaddset(&mask, SIGQUIT);
	if ((err = pthread_sigmask(SIG_BLOCK, &mask, &oldmask)) != 0)
		err_exit(err, "SIG_BLOCK error");

	err = pthread_create(&tid, NULL, thr_fn, NULL);
	if (err != 0)
		err_exit(err, "can't create thread");

#if 1
	pthread_mutex_lock(&lock);
	while (quitflag == 0)
		pthread_cond_wait(&waitloc, &lock);
	pthread_mutex_unlock(&lock);

#else
	while (quitflag == 0);

#endif


	/* SIGQUIT has been caught and now is blocked; do whatever */
	quitflag = 0;

	printf("SIG QUIT!!!\n");

	/* reset signal mask which unblocks SIGQUIT */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	exit(0);
}
