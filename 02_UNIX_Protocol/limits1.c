#include "apue.h"
#include <errno.h>
#include <limits.h>


static void pr_sysconf(char *, int);
static void pr_pathconf(char *, const char *, int);


int main(int argc, const char *argv[]) {


	if (argc != 2)
		err_sys("usage: limits1 <dirname>");

#ifdef ARG_MAX	
	printf("ARG_MAX define = %ld\n", (long int) (ARG_MAX+0));
#else
	printf("no symbol for ARG_MAX\n");
#endif

#ifdef _SC_ARG_MAX
	pr_sysconf("ARG_MAX =", _SC_ARG_MAX);
#else
	printf("no symbol for _SC_ARG_MAX\n");
#endif



#ifdef _SC_CLK_TCK
	pr_sysconf("CLK_TCK =", _SC_CLK_TCK);
#else
	printf("no symbol for _SC_CLK_TCK\n");
#endif



#ifdef MAX_CANON
	printf("MAX_CANON define = %ld\n", (long int) (MAX_CANON+0));
#else
	printf("no symbol for MAX_CANON\n");
#endif

#ifdef _PC_MAX_CANON
	pr_pathconf("MAX_CANON = ", argv[1], _PC_MAX_CANON);
#else
	printf("no symbol for _PC_MAX_CANON\n");
#endif




#ifdef NAME_MAX
	printf("NAME_MAX define = %ld\n", (long int) (NAME_MAX+0));
#else
	printf("no symbol for NAME_MAX\n");
#endif

#ifdef _PC_NAME_MAX
	pr_pathconf("NAME_MAX =", argv[1], _PC_NAME_MAX );
#else
	printf("no symbol for _PC_NAME_MAX\n");
#endif



#ifdef PATH_MAX
	printf("PATH_MAX define = %ld\n", (long int) (PATH_MAX+0));
#else
	printf("no symbol for PATH_MAX\n");
#endif

#ifdef _PC_PATH_MAX
	pr_pathconf("PATH_MAX =", argv[1], _PC_PATH_MAX);
#else
	printf("no symbol for _PC_PATH_MAX\n");
#endif


	exit(0);
}


static void pr_sysconf(char *mesg, int name) {

	long val;

	fputs(mesg, stdout);

	errno = 0;

	if ((val = sysconf(name)) < 0) {
		
		if (errno != 0) {
			if (errno == EINVAL) {
				fputs("  (not supported)\n", stdout);		
			}
			else {
				err_sys("sysconf error");
			}
		}
		else {
			fputs(" (no limit)\n", stdout);
		}
	}
	else {
		printf(" %ld\n", val);
	}
	
}

static void pr_pathconf(char *mesg, const char *path, int name) {

	long val;

	fputs(mesg, stdout);

	errno = 0;

	if ((val = pathconf(path, name)) < 0) {
		
		if (errno != 0) {
			if (errno == EINVAL) {
				fputs("  (not supported)\n", stdout);		
			}
			else {
				err_sys("pathconf error, path = %s", path);
			}
		}
		else {
			fputs(" (no limit)\n", stdout);
		}
	}
	else {
		printf(" %ld\n", val);
	}
	
}



