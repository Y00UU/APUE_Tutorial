#include "apue.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <sys/stat.h>


void daemonize(const char *cmd)
{
	int i, fd0, fd1, fd2;
	pid_t pid;
	struct rlimit rl;
	struct sigaction sa;

	// Clear file creation mask
	umask(0);

	// Get maximum number of file descripors
	if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
		err_quit("%s: can't get file limit", cmd);

	// Become a session leader to lose controlling TTY
	if ((pid = fork()) < 0)
		err_quit("%s: can't fork", cmd);
	else if (pid != 0) // parent process id
		exit(0);
	setsid();

	// Ensure future opens won't allocate controlling TTY
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0)
		err_quit("%s: can't ignore SIGHUP", cmd);
	if ((pid = fork()) < 0)
		err_quit("%s: can't fork", cmd);
	else if (pid != 0) //parent process id
		exit(0);
	else if (pid == 0)
		printf("children pid = %d\n", (unsigned int) getpid());

	// Change the current working directory to the root so we won't prevent file system from being unmounted
	if (chdir("/") < 0)
		err_quit("%s: can't change directory to /", cmd);

	// Close all open file descriptors	
	if (rl.rlim_max == RLIM_INFINITY)
		rl.rlim_max = 1024;
	for (i = 0; i < rl.rlim_max; ++i)
		close(i);

	// Attach file descriptors 0, 1, and 2 to /dev/null.
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);

	// Initialize the log file.
	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
		syslog(LOG_ERR, "unexpected file descriptors %d %d %d", fd0, fd1, fd2);
		exit(1);
	}

	// Keep children process alive 30s.
	// sleep(30);
}


/*
int main(int argc, const char *argv[])
{
	pid_t ppid;	
	char *cmd = "Test daemon creation.";

	ppid = getpid();

	printf("parent pid = %d\n", (unsigned int) ppid);

	daemonize(cmd);

	return 0;
}
*/
