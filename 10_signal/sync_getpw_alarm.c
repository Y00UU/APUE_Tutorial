#include "apue.h"
#include <pwd.h>
#include <unistd.h>


static void my_alarm(int signo) {

	struct passwd *rootptr;
	
	printf("in signal handler\n");

	if ((rootptr = getpwnam("root")) == NULL)
		err_sys("getpwnam error");
	else
		printf("signal get pw_name = %s\n", rootptr->pw_name);
	
	alarm(3);
}



#define PW_NAME "ryanlu"


int main(void) {

	struct passwd *ptr;

	signal(SIGALRM, my_alarm);

	alarm(3);

	while (1) {
		
		if ((ptr = getpwnam(PW_NAME)) == NULL)
			err_sys("getpwnam error");

		if (strcmp(ptr->pw_name, PW_NAME) != 0)
			printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
		
		// sleep(1);
	}
}

