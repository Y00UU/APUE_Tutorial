#include "apue.h"


extern int system(const char *);

extern void pr_exit(int);



int main(int argc, const char *argv[]) {

	int status;

	if (argc != 2)
		err_sys("usage: ./a.out command");

	status = system(argv[1]);
	
	pr_exit(status);

	exit(0);
}


