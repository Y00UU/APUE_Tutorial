#include <unistd.h>
#include <stdio.h>

extern int already_running(void);

int main(void) 
{
	int status;

	printf("The %ld process already running\n", (long int) getpid());	

	status = already_running();

	if (status != 0) {
		printf("The %ld process run failed!\n", (long int) getpid());
	}
	else {
		printf("The %ld process run sucessfully!\n", (long int) getpid());
	}

	return 0;
}
