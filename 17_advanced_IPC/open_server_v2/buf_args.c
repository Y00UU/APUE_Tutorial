#include "apue.h"

#define MAXARGC	(50)			// max number of arguments in buf
#define WHITE	" \t\n"			// whites space for tokenizing arguments

/*
 * buf[] contains white-sapce-separated arguments. We convert it to an
 * argv-style array of pointer, and call the user's function (optfunc)
 * to process the array.
 *
 *
 */

int buf_args(char *buf, int (*optfunc)(int, char **))
{
	char *ptr, *argv[MAXARGC];
	int argc;

	// an argv[0] is requeired
	if (strtok(buf, WHITE) == NULL)
		return (-1);
	argv[argc = 0] = buf;
	while ((ptr = strtok(NULL, WHITE)) != NULL) {
		if (++argc >= MAXARGC - 1)		// -1 for room for NULL at end
			return (-1);
		argv[argc] = ptr;
	}
	argv[++argc] = NULL;


	// Since argv[] pointers point into the user's buf[],
	// user's function can just copy the poninters, even though
	// argv[] array will disappear on return.
	
	return ((*optfunc)(argc, argv));
}
