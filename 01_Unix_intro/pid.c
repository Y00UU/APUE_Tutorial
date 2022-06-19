#include "apue.h"


int main(int argc, const char *argv[]) {


	pid_t id = getpid();


	printf("hello world from process id %ld\n", (long int)id);

	exit(0);

}
