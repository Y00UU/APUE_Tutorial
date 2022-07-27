#include "cond_t_mutex.h"
#include <pthread.h>
#include <stdio.h>


static struct msg *workq;
static pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;


void process_msg(void) {

	struct msg *mp;

	while (1) {
	
		pthread_mutex_lock(&qlock);
		
		while (workq == NULL)
			pthread_cond_wait(&qready, &qlock);

		mp = workq;
		workq = mp->m_next;
		pthread_mutex_unlock(&qlock);

		/* new pocess the message mp */
		printf("job_id = %ld\n", mp->job_id);
		fflush(stdout);
	}
}


void enqueue_msg(struct msg *mp) {

	pthread_mutex_lock(&qlock);
	mp->m_next = workq;
	workq = mp;
	pthread_mutex_unlock(&qlock);
	pthread_cond_signal(&qready);

}
