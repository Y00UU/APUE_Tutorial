#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef OPEN_MAX
static long int openmax = OPEN_MAX;
#else
static long int openmax = 0;
#endif


#define OPEN_MAX_GUESS	(256)


long int open_max(void) {

	if (openmax == 0) {
		errno = 0;

		if ((openmax = sysconf(_SC_OPEN_MAX)) < 0) {
		
			if (errno == 0) 
				openmax = OPEN_MAX_GUESS;
			else
				err_sys("sysconf error for _SC_OPEN_MAX");
		}

	}

	return openmax;
}


int main(void) {

	long int openmax = open_max();

	if (openmax > 0)
		printf("open max = %ld\n", openmax);
	else
		err_sys("open max error");
}


