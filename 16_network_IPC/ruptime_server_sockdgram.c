#include "apue.h"
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <syslog.h>

#define BUFLEN	(128)
#define MAXADDRLEN	(256)

extern void daemonize(const char *);
extern int initserver(int, const struct sockaddr *, socklen_t, int);
extern int set_cloexec(int);

void serve(int sockfd)
{
	int n;
	socklen_t alen;
	FILE *fp;
	char buf[BUFLEN];
	char abuf[MAXADDRLEN];
	struct sockaddr *addr = (struct sockaddr *) abuf;

	set_cloexec(sockfd);
	for (;;) {
		alen = MAXADDRLEN;
		if ((n = recvfrom(sockfd, buf, BUFLEN, 0, addr, &alen)) < 0) {
			syslog(LOG_ERR, "ruptime: recvfrom error: %s", strerror(errno));
			exit(1);
		}
		if ((fp = popen("/usr/bin/uptime", "r")) == NULL) {
			sprintf(buf, "error: %s\n", strerror(errno));
			sendto(sockfd, buf, strlen(buf), 0, addr, alen);
		}
		else {
			if (fgets(buf, BUFLEN, fp) != NULL)
				sendto(sockfd, buf, strlen(buf), 0, addr, alen);
			pclose(fp);
		}
	}
}

int main(int argc, char *argv[])
{
	struct addrinfo *ailist, *aip;
	struct addrinfo hint;
	int sockfd, err, n;

	if (argc != 3)
		err_quit("usage: %s <host> <server/port>", argv[0]);
	
	daemonize("ruptimed");

	memset(&hint, 0, sizeof(hint));
	hint.ai_flags = AI_PASSIVE;
	hint.ai_socktype = SOCK_DGRAM;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;

	if ((err = getaddrinfo(argv[1], argv[2], &hint, &ailist)) != 0) {
		syslog(LOG_ERR, "ruptiem: getaddrinfo error: %s", gai_strerror(err));
		exit(1);
	}

	for (aip = ailist; aip != NULL; aip = aip->ai_next) {
		if((sockfd = initserver(SOCK_DGRAM, aip->ai_addr, aip->ai_addrlen, 0)) >= 0) {
			serve(sockfd);
			exit(0);
		}
	}

	exit(1);
}

