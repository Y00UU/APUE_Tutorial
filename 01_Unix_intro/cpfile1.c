#include "apue.h"

#define BUFFSIZE (4096)

int main(int argc, const char *argv[]) {
   	
    int n = -1;
    char buf[BUFFSIZE] = {0};

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	if (write(STDOUT_FILENO, buf, n) != n)
		err_sys("wirte error");
    if (n < 0)
	err_sys("read error");

    exit(0);
}
