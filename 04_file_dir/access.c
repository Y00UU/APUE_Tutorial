#include "apue.h"
#include <fcntl.h>

int main(int argc, const char *argv[]) {
	
	if (argc != 2)
		err_sys("usage: access <pathname>");

	if (access(argv[1], R_OK) < 0)
		err_ret("access error for %s", argv[1]);

	else
		printf("read access OK\n");

	if (open(argv[1], O_RDONLY) < 0)
		err_ret("open error for %s", argv[1]);

	else
		printf("open for reading OK\n");

	exit(0);
}


