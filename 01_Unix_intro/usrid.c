#include "apue.h"

int main(void) {
	
	int uid = getuid();

	int gid = getgid();

	printf("uid = %d, gid = %d\n", uid, gid);

	exit(0);
}

