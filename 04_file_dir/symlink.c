#include "apue.h"



int main(int argc, const char *argv[]) {

	if (argc != 2)
		err_sys("usage: symlink <sympath>");

	if (symlink("./tempdir/tempfile", argv[1]) < 0)
		err_sys("error symlink");
	char buf[4096];

	ssize_t len = readlink(argv[1], buf, 4096);
	
	if (len > 0) {
		buf[len+1] = '\0';
		printf("symlink actual file name is: %s", buf);
	}

	exit(0);
}



