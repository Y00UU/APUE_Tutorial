#include "apue.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

// Pointer to array allocated at run-time.
static pid_t *childpid = NULL;

// From our open_max()
static int maxfd;

FILE *my_popen(const char *cmdstring, const char *type)
{
	int i;
	int pfd[2];
	pid_t pid;
	FILE *fp;

	// only allow "r" or "w"
	if ((type[0] != 'r' && type[0] != 'w') || type[1] != '\0') {
		errno = EINVAL;
		return (NULL);
	}

	// first time through
	if (childpid == NULL) {
		// allocate zeroed out array for child pids.
		maxfd = open_max();
		if ((childpid = calloc(maxfd, sizeof(pid_t))) == NULL)
			return (NULL);
	}

	if ((pid = fork()) < 0) {
		return NULL;
	}
	else if (pid == 0) {
		if (type[0] == 'r') {
			close(pfd[0]);
			if (pfd[1] != STDOUT_FILENO) {
				dup2(pfd[1], STDOUT_FILENO);
				close(pfd[0]);
			}
		}
		else {
			close(pfd[1]);
			if (pfd[0] != STDIN_FILENO) {
				dup2(pfd[0], STDIN_FILENO);
				close(pfd[0]);
			}
		}

		// close all decriptors in childpid[]
		for (i = 0; i < maxfd; ++i)
			if (childpid[i] > 0)
				close(i);

		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0); 
		_exit(127);
	}

	// parent continues
	if (type[0] == 'r') {
		close(pfd[1]);
		if ((fp = fdopen(pfd[0], type)) == NULL)
			return (NULL);
	}
	else {
		close(pfd[0]);
		if ((fp = fdopen(pfd[1], type)) == NULL)
			return (NULL);
	}

	// remenber child pid for thid fd.
	childpid[fileno(fp)] = pid;
	return (fp);
}

int my_pclose(FILE *fp)
{
	int fd, stat;
	pid_t pid;

	if (childpid == NULL) {
		errno = EINVAL;
		return (-1); // popen() has never been called
	}
	
	fd = fileno(fp);
	if (fd >= maxfd) {
		errno = EINVAL;
		return (-1);
	}
	
	if ((pid = childpid[fd]) == 0) {
		errno = EINVAL;
		return (-1);
	}

	childpid[fd] = 0;
	if (fclose(fp) == EOF)
		return -1;

	while (waitpid(pid, &stat, 0) < 0)
		if (errno != EINTR)
			return (-1);

	return stat;
}

