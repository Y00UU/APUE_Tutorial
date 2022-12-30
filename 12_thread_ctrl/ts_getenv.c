#include "apue.h"
#include <stdio.h>

extern char *getenv(const char *name);



int main(int argc, const char *argv[])
{
	
	char *env;

	if (argc < 2)
	{
		err_quit("usage: 2 arguments!");
		return -1;
	}

	env = getenv(argv[1]);
	
	printf("getenv: %s\n", env);


	return 0;
}
