#include <stdlib.h>
#include <pthread.h>

#define NHASH 29
#define HASH(id) (((unsigned long)id)%NHASH)


/* hash linklist */
static struct foo *fh[NHASH];


static pthread_mutex_t hashlock = PTHREAD_MUTEX_INITIAIZER;

/* linklist */
struct foo {
	int f_count;
	pthread_mutex_t f_lock;
	int f_id;
	struct foo *f_next;
	int f_idx;
};


struct foo *foo_alloc(int id) {
	struct foo *fp;
	int idx;


	if ((fp = malloc(sizeof(struct foo))) != NULL) {
	
		fp->count = 1;
		fp->f_id = id;
		
		if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
			free(fp);
			return(NULL);
		}

		idx = HASH(id);
		
		pthread_mutex_lock(&hashlock);
		
		fp->f_next = fh[idx];          // head insert
		fh[idx] = fp;				  // head insert
		pthread_mutex_lock(&fp->f_lock);

		pthread_mutex_unlock(&hashlock);

			/* continue initialization... */
		
		fp->idx = idx;

		pthread_mutex_unlock(&fp->f_lock);
	}

	return (fp);
}


void foo_hold(struct foo *fp) {
	
	pthread_mutex_lock(&fp->f_lock);
	fp->f_count++;
	pthread_mutex_unlock(&fp->f_lock);

}

struct foo *foo_find(int id) {

	struct foo *fp = NULL;

	pthread_mutex_lock(&hashlock);

	for (fp = fh[HASH(id)]; fp != NULL; fp = fp->f_next) {
		if (fp->id == id) {
			foo_hold(fp);
			break;
		}
	}


	pthread_mutex_unlock(&hashlock);
	return (fp);
}

void foo_rele(struct foo *fp) {
	
	struct foo *tfp;
	int idx;


	phread_mutex_lock(&fp->f_lock);
	if (fp->f_count == 1) {
		pthread_mutex_unlock(&fp->f_lock);

		pthread_mutex_lock(&hashlock);
		
		pthread_mutex_lock(&fp->f_lock);
		if (fp->f_count != 1) {
			fp->f_count--;
			pthread_mutex_unlock(&fp->f_lock);

			pthread_mutex_unlock(&hashlock);
			return ;
		}

		/* remove */
		idx = HASH(fp->f_id);
		tfp = fh[idx];
		if (tfp == fp) {
			fh[idx] = fp->f_next;
		}
		else {
			
			while (tfp->f_next != fp)
				tfp = tfp->f_next;
			
			tfp->f_next = fp->f_next;
		}

		pthread_mutex_unlock(&hashlock);
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_destroy(&fp->f_lock);

		free(fp);

	}
	else {
		fp->f_count--;
		pthread_mutex_unlock(&fp->f_lock);
	}
}



