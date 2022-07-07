#include "apue.h"
#include <sys/wait.h>
#include "pr_exit.h"


int main(void) {

	pid_t pid;
	int status;

	if ((pid = fork()) < 0)
		err_sys("fork error");

	else if (pid == 0)
		exit(0x1234);

	if (wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);




	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		abort();				/* SIGABRT = 6*/

	if (wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);




	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		status /= 0;				/* SIGFPE = 8 */

	if (wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);
	

	exit(0);
}
