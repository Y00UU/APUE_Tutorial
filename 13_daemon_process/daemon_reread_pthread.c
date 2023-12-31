#include "apue.h"
#include <pthread.h>
#include <syslog.h>
#include <string.h>

sigset_t mask;

extern void daemonize(const char *cmd);
extern int already_running(void);

void reread(void)
{
	/* reread daemon configure file  */
}

void *thr_fn(void *arg)
{
	int err, signo;

	for (;;) {
		err = sigwait(&mask, &signo);
		if (err != 0) {
			syslog(LOG_ERR, "sigwait failed!");
			exit(1);
		}

		switch (signo) {
		case SIGHUP:
			syslog(LOG_INFO, "Re-reading configuration file");
			reread();
			break;
		case SIGTERM:
			syslog(LOG_INFO, "got SIGTERM; exiting");
			exit(0);
			break;
		default:
			syslog(LOG_INFO, "unexcepted signal %d\n", signo);
		}
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	int err;
	pthread_t tid;
	char *cmd;
	struct sigaction sa;

	if ((cmd = strrchr(argv[0], '/')) == NULL)
		cmd = argv[0];
	else
		cmd++;
	
	// Become a daemon
	daemonize(cmd);

	// Make sure only one copy of the daemon is running.
	if (already_running() != 0) {
		syslog(LOG_ERR, "daemon already running");
		exit(1);
	}

	// Restore SIGHUP default and block all signals.
	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0)
		err_quit("%s: can't restore SIGHUP default");
	sigfillset(&mask);
	if ((err = pthread_sigmask(SIG_BLOCK, &mask, NULL)) != 0)
		err_exit(err, "SIG_BLOCK error");

	// Create a thread to handle SIGHUP and SIGTERM
	err = pthread_create(&tid, NULL, thr_fn, NULL);
	
	if (err != 0)
		err_exit(err, "can't create thread");

	/* Process with the rest of the daemon  */


	exit(0);
}
