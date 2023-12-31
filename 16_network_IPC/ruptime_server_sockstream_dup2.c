#include "apue.h"
#include <netdb.h>
#include <errno.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define QLEN	(128)
#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX
#endif

extern void daemonize(const char *cmd);
extern int initserver(int, const struct sockaddr *, socklen_t, int);
extern int set_cloexec(int);

void serve(int sockfd)
{
	int clfd, status;
	pid_t pid;

	set_cloexec(sockfd);
	for (;;) {
		if ((clfd = accept(sockfd, NULL, NULL)) < 0) {
			syslog(LOG_ERR, "ruptimed: accept: %s", strerror(errno));
			exit(1);
		}
		if ((pid = fork()) < 0) {
			syslog(LOG_ERR, "ruptimed: fork error: %s", strerror(errno));
			exit(1);
		}
		else if (pid == 0) {
			//child process
			if (dup2(clfd, STDOUT_FILENO) != STDOUT_FILENO || dup2(clfd, STDERR_FILENO) != STDERR_FILENO) {
				syslog(LOG_ERR, "ruptimed: unexpected");
				exit(1);
			}		
			close(clfd);
			execl("/usr/bin/uptime", "uptime", (char *)0);
			syslog(LOG_ERR, "ruptimed: unexpected return from exec: %s", strerror(errno));
		}
		else {
			// parent process
			close(clfd);
			if (waitpid(pid, NULL, 0) < 0)
				err_sys("waitpid error");
		}
	}
}

int main(int argc, char *argv[])
{
	struct addrinfo *ailist, *aip;
	struct addrinfo hint;
	int sockfd, err, n;
	
	if (argc != 3)
		err_quit("usage: %s <host> <server>", argv[0]);

	daemonize("ruptime");

	memset(&hint, 0, sizeof(hint));
	hint.ai_flags = AI_PASSIVE;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;
	
	if ((err = getaddrinfo(argv[1], argv[2], &hint, &ailist)) != 0) {
		syslog(LOG_ERR, "ruptimed: getaddrinfo error: %s", gai_strerror(err));
		exit(1);
	}

	for (aip = ailist; aip != NULL; aip = aip->ai_next) {
		if ((sockfd = initserver(SOCK_STREAM, aip->ai_addr, aip->ai_addrlen, QLEN)) >= 0) {
			serve(sockfd);
			exit(0);
		}
	}
	exit(0);
}
