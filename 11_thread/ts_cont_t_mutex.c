#include "cond_t_mutex.h"
#include "apue.h"
#include <unistd.h>
#include <stdlib.h>

#define NTHR	(8)


static void *proc_task(void *arg) {

	while (1) {
	
		process_msg();
	
		sleep(1);
	}

	
	pthread_exit((void *) 2);
}

static void *enqueue_task(void *arg) {

	int i;

	struct msg msg_list[NTHR];

	for (i = 0; i < NTHR; ++i)
		
	


	pthread_exit((void *) 1);
}




int main(void) {

	pthread_t tid_process, tid_enqueue;
	int err;
	
	err = pthread_crete(&tid_process, NULL, proc_task, NULL);
	if (err != 0)
		err_exit(err, "can't crate thread process");

	err = pthread_create(&tid_enqueue, NULL, enqueue_task, NULL);
	if (err != 0)
		err_exit(err, "can't crate thread enqueue");

	pthread_join(tid_process, NULL);
	pthread_join(tid_enqueue, NULL);

	exit(0);
}
