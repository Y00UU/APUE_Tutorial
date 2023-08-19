#include "apue.h"
#include <stdio.h>
#include <unistd.h>

extern FILE *my_popen(const char *, const char *);
extern int my_pclose(FILE *);

#define PAGER	"${PAGER:-more}"

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	char line[MAXLINE];

	if (argc != 2)
		err_quit("usage: a.out <pathname>");

	if ((fin = fopen(argv[1], "r")) == NULL)
		err_sys("fopen error: %s", argv[1]);

	if ((fout = my_popen(PAGER, "w")) == NULL)
		err_sys("popen error: %s", PAGER);

	// copy argv[1] tp pager
	while (fgets(line, MAXLINE, fin) != NULL) {
		if (fputs(line, fout) == EOF)
			err_sys("fputs error to pipe: %s", line);
	}

	if (ferror(fin))
		err_sys("fgets error");
	if (my_pclose(fout) == -1)
		err_sys("pclose error");

	exit(0);
}

