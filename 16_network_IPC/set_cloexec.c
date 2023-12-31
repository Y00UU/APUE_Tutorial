#include "apue.h"
#include <fcntl.h>

int set_cloexec(int fd)
{
	int val;

	if ((val = fcntl(fd, F_GETFD, 0)) < 0)
		return (-1);

	// enable close-on-exec
	val |= FD_CLOEXEC;

	return (fcntl(fd, F_SETFD, val));
}

