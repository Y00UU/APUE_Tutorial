#include "apue.h"
#include <sys/wait.h>
#include "pr_exit.h"



int main(void) {
	
	int status;
	pid_t pid;


	if ((pid = fork()) < 0) {
		err_sys("parent fork error");
	}
	else if (pid == 0) {
		if ((pid = fork()) < 0) {
			err_sys("first child fork error");
		}
		else if (pid == 0) {
			printf("second child sleep 5s...\n");
			sleep(5);
			printf("second child done, parent pid = %ld, pid = %ld\n", (long int) getppid(), (long int) getpid());
			exit(0);	
		}
		else if (pid > 0) {
			printf("first child done, parent pid = %ld, pid = %ld\n", (long int) getppid(), (long int) getpid());
			exit(0x1234);
		}

	}
	else if (pid > 0) {
	
		if (waitpid(pid, &status, 0) != pid)
			err_sys("wait first child error, pid = %ld\n", (long int) pid);
		pr_exit(status);
		
		printf("parent done, pid = %ld, first child pid = %ld\n", (long int) getpid(), (long int) pid);
		exit(0);
	}

	exit(0);
}

