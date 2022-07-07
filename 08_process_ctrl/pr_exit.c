#include <stdio.h>
#include <sys/wait.h>
#include "pr_exit.h"

void pr_exit(int status) {

	if (WIFEXITED(status))
		printf("normal termination, exit status low 8 bit = %#x\n", WEXITSTATUS(status));

	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status), 

#ifdef WCOREDUMP
		WCOREDUMP(status) ? " (core file generated)" : "");
#else
		"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));

	else if (WIFCONTINUED(status))
		printf("child continued, status = %d\n", status);
}

#if 0
int main(void) {

	return 0;
}
#endif
