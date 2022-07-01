#include "apue.h"


int main(void) {


	char buf[MAXLINE];

	/* fgets is I/O BLOCK operator */
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		
		// putchar('1');

		if (fputs(buf, stdout) == EOF)
			err_sys("output error");

	}
	if (ferror(stdin))
		err_sys("input error");


	exit(0);
}



