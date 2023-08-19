#include "apue.h"
#include <sys/shm.h>
#include <stdlib.h>

#define ARRAY_SIZE		(40000)	/*40KB*/
#define MALLOC_SIZE		(100000) // 100KB
#define SHM_SIZE		(100000) // 100KB
#define SHM_MODE		(0600) // user read/write

char array[ARRAY_SIZE];			// uninitialized data = bss

int main(void)
{
	int shmid;
	char *ptr, *shmptr;

	// bbs
	printf("array[] from %p to %p\n", (void *)&array[0], (void *)&array[ARRAY_SIZE]);
	
	// stack
	printf("stack around %p\n", (void *)&shmid);

	// heap
	if ((ptr = (char *) malloc(MALLOC_SIZE)) == NULL)
		err_sys("malloc error");
	printf("malloced from %p to %p\n", (void *)ptr, (void *)(ptr + MALLOC_SIZE));

	// shm
	if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, SHM_MODE)) < 0)
		err_sys("shmget error");
	if ((shmptr = (char *)shmat(shmid, 0, 0)) == (char *)(-1))
		err_sys("shmat error");
	printf("shared memory attached from %p to %p\n", (void *)shmptr, (void *)(shmptr+SHM_SIZE));

	if (shmctl(shmid, IPC_RMID, 0) < 0)
		err_sys("shmctl error");

	exit(0);
}

