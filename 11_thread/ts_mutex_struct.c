#include "mutex_struct.h"
#include "apue.h"
#include <unistd.h>


static struct foo *fp;	
static unsigned int final_f_tmp;

static void *thr_fn1(void *arg) {
	
	if (fp)
		foo_hold(fp);
	
	while (fp && fp->f_tmp) {
		fp->f_tmp--;
		final_f_tmp = fp->f_tmp;
		usleep(1);
	}
	
	if (fp)
		foo_rele(fp);

	printf("thread 1 exit\n");
	fflush(stdout);

	pthread_exit(NULL);
}

static void *thr_fn2(void *arg) {

	unsigned int cnt = 500000UL;
	
	foo_hold(fp);
	
	usleep(2);
	while (fp && fp->f_tmp && cnt) {
		fp->f_tmp--;
		cnt--;
		final_f_tmp = fp->f_tmp;
		usleep(1);
	}
	
	if (fp)
		foo_rele(fp);
	
	printf("thread 2 exit\n");
	fflush(stdout);

	pthread_exit(NULL);
}

static void *thr_fn3(void *arg) {

	unsigned int cnt = 490000UL;

	if (fp)
		foo_hold(fp);

	usleep(4);
	while (fp && fp->f_tmp && cnt) {
		fp->f_tmp--;
		cnt--;
		final_f_tmp = fp->f_tmp;
		usleep(1);
	}
	
	if (fp)
		foo_rele(fp);
	
	printf("thread 3 exit\n");
	fflush(stdout);

	pthread_exit(NULL);
}






int main(void) {

	pthread_t tid1, tid2, tid3;


	fp = foo_alloc(1);
	fp->f_tmp = 1000000UL;

	pthread_create(&tid1, NULL, thr_fn1, NULL);
	pthread_create(&tid2, NULL, thr_fn2, NULL);
	pthread_create(&tid3, NULL, thr_fn3, NULL);

	while (fp && fp->f_tmp > 0) {
		printf("fp->f_tmp = %u\n", fp->f_tmp);
		sleep(1);
	}

	printf("final_f_tmp = %u\n", final_f_tmp);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	exit(0);
}

