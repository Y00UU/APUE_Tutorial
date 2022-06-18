#include "apue.h"

int main(int argc, const char *argv[]) {

	int c = -1;

	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF)
			err_sys("ouput error");

	if (ferror(stdin))
		err_sys("input error");

	exit(0);
}
