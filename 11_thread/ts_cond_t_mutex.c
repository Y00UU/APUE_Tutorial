#include "cond_t_mutex.h"
#include "apue.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define NTHR	(8)
static struct msg msg_list[NTHR];


static void *proc_task(void *arg) {
	
	printf("proc_task is running...\n");

	// sleep(1);
	
	process_msg();
	
	pthread_exit((void *) 2);
}

static void *enqueue_task(void *arg) {

	int i;
	
	// sleep(1);

	for (i = 0; i < NTHR; ++i) {
		msg_list[i].job_id = (long int) i;
		enqueue_msg(&msg_list[i]);
	}

	pthread_exit((void *) 1);
}




int main(void) {

	pthread_t tid_process, tid_enqueue;
	int err;
	
	err = pthread_create(&tid_process, NULL, proc_task, NULL);
	if (err != 0)
		err_exit(err, "can't crate thread process");

	err = pthread_create(&tid_enqueue, NULL, enqueue_task, NULL);
	if (err != 0)
		err_exit(err, "can't crate thread enqueue");

	pthread_join(tid_process, NULL);
	pthread_join(tid_enqueue, NULL);

	exit(0);
}
