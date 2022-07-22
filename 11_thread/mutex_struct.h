#ifndef MUTEX_STRUCT
#define MUTEX_STRUCT

#include <pthread.h>

struct foo {
	int f_count;
	pthread_mutex_t f_lock;
	int f_id;
	unsigned int f_tmp;
	struct foo *f_next;

	/* more stuff here */
};

struct foo *foo_alloc(int id);
void foo_hold(struct foo *fp);
void foo_rele(struct foo *fp);


#endif
