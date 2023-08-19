#include "apue.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CMDSTRING	"$PWD/myuclc.out"

int main(void)
{
	char line[MAXLINE];
	FILE *fpin;

	if ((fpin = popen(CMDSTRING, "r")) < 0)
		err_sys("popen error");

	for (; ;) {
		fputs("prompt>", stdout);
		fflush(stdout);
		if (fgets(line, MAXLINE, fpin) == NULL)
			break;
		if (fputs(line, stdout) == EOF)
			err_sys("fputs error to pipe");
		fflush(stdout);
	}
	
	if (pclose(fpin) == -1)
		err_sys("pclose error");

	putchar('\n');

	exit(0);
}
