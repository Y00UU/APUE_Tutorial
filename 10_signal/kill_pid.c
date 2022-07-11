#include "apue.h"


int main(void) {

	pid_t pid;
	char buf[MAXLINE];

	pid = getpid();
	printf("current process pid = %ld\n", (long int) getpid());
	
	printf("(get character from key)%%: ");
	if (fgets(buf, MAXLINE, stdin) == NULL)
		err_sys("fget error");

	printf("buf: %s\n", buf);

	exit(0);
}


