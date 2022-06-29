#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef PATH_MAX
static long int pathmax = PATH_MAX+0;
#else
static long pathmax = 0;
#endif


static long int posix_version = 0;
static long int xsi_version = 0;


#define PATH_MAX_GUESS	(1024)


char *path_alloc(size_t *sizep) {

	char *ptr;
	size_t size;

	if (posix_version == 0)
		posix_version = sysconf(_SC_VERSION);

	if (xsi_version == 0)
		xsi_version = sysconf(_SC_XOPEN_VERSION);

	if (pathmax == 0) {
	
		errno = 0;

		if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) {
			if (errno == 0)
				pathmax = PATH_MAX_GUESS;
			else
				err_sys("pathconf error for _PC_PATH_MAX");
		}
		else {
			pathmax++;
		}
	}



	if (posix_version < 200112L && xsi_version < 4)
		size = pathmax + 1;
	else
		size = pathmax;


	if ((ptr = (char *)malloc(size)) == NULL)
		err_sys("malloc error for pathname");

	if (sizep != NULL)
		*sizep = size;

	return ptr;

}


int main(void) {
	
	char *path_ptr;
	size_t path_ptr_size;

	path_ptr = path_alloc(&path_ptr_size);


	if (path_ptr_size > 0)
		printf("path alloc memory successful.size = %ld\n", path_ptr_size);
	else
		err_sys("path alloc error");

	exit(0);
}

