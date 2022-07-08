#include <stdio.h>



int main(int argc, const char *argv[]) {
	
	int i;
	char **ptr;

	for (i = 0; i < argc; ++i)
		printf("argv[%d]: %s\n", i, argv[i]);

	return 0;
}


