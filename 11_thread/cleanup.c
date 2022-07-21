#include "apue.h"
#include <pthread.h>
// #include <unistd.h>


void *thr_fn4(void *arg);

void cleanup(void *arg) {
	printf("cleanup: %s\n", (char *) arg);
}

void *thr_fn1(void *arg) {
	printf("thread 1 start\n");
	pthread_cleanup_push(cleanup, "thread 1 first handler");
	pthread_cleanup_push(cleanup, "thread 1 second handler");
 	printf("thread 1 push complete\n");
	fflush(stdout);

	if (arg) 
		return ((void *) 1);

	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	return ((void *) 1);
}

void *thr_fn2(void *arg) {
	printf("thread 2 start\n");
	pthread_cleanup_push(cleanup, "thread 2 first handler");
	pthread_cleanup_push(cleanup, "thread 2 second handler");
	printf("thread 2 push complete\n");
	fflush(stdout);

	if (arg)
		pthread_exit(((void *) 2));
	
 	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
 	pthread_exit(((void *) 2));
}

void *thr_fn3(void *arg) {
	printf("thread 3 start\n");
	pthread_cleanup_push(cleanup, "thread 3 first handler");
	pthread_cleanup_push(cleanup, "thread 3 second handler");
	pthread_cleanup_push(cleanup, "thread 3 third handler");
	printf("thread 3 push complete\n");
	fflush(stdout);

	if (arg) 
		return ((void *) 3);

	pthread_cleanup_pop(1);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(1);
	return ((void *) 3);
}

#if 0
#endif

int main(void) {

	int err;
	pthread_t tid1, tid2, tid3, tid4;
	void *tret;
	
	printf("create thread start\n");
	
	err = pthread_create(&tid1, NULL, thr_fn1, (void *) (1));
	if (err != 0)
		err_exit(err, "can't create thread 1");

	err = pthread_create(&tid2, NULL, thr_fn2, (void *) (1));
	if (err != 0)
		err_exit(err, "can't create thread 2");

	err = pthread_create(&tid3, NULL, thr_fn3, NULL);
	if (err != 0)
		err_exit(err, "can't create thread 3");

	/* err = pthread_create(&tid4, NULL, thr_fn4, (void *) (1)); */
	/* if (err != 0) */
		/* err_exit(err, "can't create thread 4"); */
	









	err = pthread_join(tid1, &tret);
	if (err != 0)
		err_exit(err, "can't join with thread 1");
	printf("thread 1 exit code %ld\n", (long int) tret);

	err = pthread_join(tid2, &tret);
	if (err != 0)
		err_exit(err, "can't join with thread 2");
	printf("thread 2 exit code %ld\n", (long int) tret);
	
	err = pthread_join(tid3, &tret);
	if (err != 0)
		err_exit(err, "can't join with thread 3");
	printf("thread 3 exit code %ld\n", (long int) tret);

	// err = pthread_join(tid4, &tret);
	// if (err != 0)
		// err_exit(err, "can't join with thread 4");
	// printf("thread 4 exit code %ld\n", (long int) tret);



#if 0
#endif
	
	
	exit(0);

}
void *thr_fn4(void *arg) {
	printf("thread 4 start\n");
	pthread_cleanup_push(cleanup, "thread 4 first handler");
	pthread_cleanup_push(cleanup, "thread 4 second handler");
	printf("thread 4 push complete\n");
	fflush(stdout);

	if (arg) 
		return ((void *) 4);

	return ((void *) 4);
}

