#include <unistd.h>

#include <stdarg.h>

#include <stdio.h>

#include <stdint.h>


ssize_t my_pr(const char *, ...);


int main(int argc, const char *argv[]) {

	if (argc != 3)
		return -1;	

	return my_pr(argv[1], argv[2]);

}

ssize_t my_pr(const char *fmt, ...) {
	
	char buf[4096];

	va_list ap;
	va_start(ap, fmt);

	ssize_t len = vsprintf(buf, fmt, ap);

	va_end(ap);

	return write(STDOUT_FILENO, buf, len);
}








