#include "apue.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define NLOOPS (1000)
#define SIZE sizeof(long) //size of shared memory area

static int update(void *ptr)
{
	return (*((long *)ptr))++; // return value before increment
}

int main(void)
{
	int fd, i, counter;
	pid_t pid;
	void *area = NULL;
	
	if ((fd = open("/dev/zero", O_RDWR)) < 0)
		err_sys("open error");
	if ((area = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
		err_sys("map error");
	close(fd); // can close  /dev/zero now that it's mapped

	TELL_WAIT();
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	}
	else if (pid > 0) {
		// parent 
		for (i = 0; i < NLOOPS; i+=2) {
			if ((counter = update(area)) != i)
				err_quit("parent: excepted %d, got %d", i, counter);
			TELL_CHILD(pid);
			WAIT_CHILD();
		}

		if (waitpid(pid, NULL, 0) < 0)
			err_sys("waitpid error");

		printf("area = %ld\n", *((long *) area));
	}
	else {
		// child
		for (i = 1; i < NLOOPS + 1; i+=2) {
			WAIT_PARENT();

			if ((counter = update(area)) != i)
				err_quit("child: excepted %d, got %d", i, counter);

			TELL_PARENT(getppid());
		}
	}

	exit(0);
}

