#include <stdio.h>

int main(int argc, const char *argv[]) {

	int i;

	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);

	for (i = 0; argv[i] != NULL; ++i)
		printf("arg%d: %s\n", i, argv[i]);


	return 0;
}

