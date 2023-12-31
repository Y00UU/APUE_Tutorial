#if defined(__APPLE__)
#include "pthread_barrier.h"

#endif

#include "apue.h"
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include <stdlib.h>


#define NTHR	(8)
#define NUMNUM	(8000000L)
#define TNUM	(NUMNUM/NTHR)


long int nums[NUMNUM];
long int snums[NUMNUM];


static pthread_barrier_t b;


#if defined(SOLARIS) || defined(__linux__)
/* extern int qsort(void *, size_t, size_t, int (*)(const void *, const void *)); */
#define heapsort	qsort

#else
extern int heapsort(void *, size_t, size_t, int (*)(const void *, const void *));

#endif


int complong(const void *arg1, const void *arg2) {

	long l1 = *(long int *) arg1;
	long l2 = *(long int *) arg2;

	if (l1 == l2)
		return 0;
	else if (l1 < l2)
		return -1;
	else
		return 1;
}

void *thr_fn(void *arg) {

	long int idx = (long int) arg;

	heapsort(&nums[idx], TNUM, sizeof(long int), complong);

	pthread_barrier_wait(&b);

	return ((void *) 0);
}

void merge(void) {

	long int idx[NTHR];
	long int i, minidx, sidx, num;

	for (i = 0; i < NTHR; ++i)
		idx[i] = i * TNUM;

	for (sidx = 0; sidx < NUMNUM; sidx++) {
		
		num = LONG_MAX;
		for (i = 0; i < NTHR; ++i) {
			if ((idx[i] < (i+1)*TNUM) && (nums[idx[i]] < num)) {
				num = nums[idx[i]];
				minidx = i;
			}
		}
		snums[sidx] = nums[idx[minidx]];
		idx[minidx]++;
	}
}


int main(void) {

	unsigned long int i;
	struct timeval start, end;
	long long startusec, endusec;
	double elapsed;
	int err;
	pthread_t tid;

	srandom(1);
	for (i = 0; i < NUMNUM; ++i)
		nums[i] = random();


	gettimeofday(&start, NULL);
	
	pthread_barrier_init(&b, NULL, NTHR+1);
	for (i = 0; i < NTHR; ++i) {
		err = pthread_create(&tid, NULL, thr_fn, (void *)(i * TNUM));
		if (err != 0)
			err_exit(err, "can't create thread");
	}
	pthread_barrier_wait(&b);
	merge();

	gettimeofday(&end, NULL);

	startusec = start.tv_sec * 1000000 + start.tv_usec;
	endusec = end.tv_sec * 1000000 + end.tv_usec;
	elapsed = (double) (endusec - startusec) / 1000000.0;
	printf("sort took %.4f seconds\n", elapsed);
	// for (i = 0; i < NUMNUM; ++i)
		// printf("%ld\n", snums[i]);
	
	exit(0);
}



