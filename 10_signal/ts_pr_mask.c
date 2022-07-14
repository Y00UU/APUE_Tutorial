#include <stdio.h>
#include <signal.h>

void pr_mask(const char *);

int main(void) {

	char *name = "ts_pr_mask";
	
	sigset_t new_set, del_set;
	
	pr_mask(name);

	sigemptyset(&new_set);
	sigaddset(&new_set, SIGINT);
	sigaddset(&new_set, SIGUSR1);
	sigaddset(&new_set, SIGUSR2);

	if (sigprocmask(SIG_BLOCK, &new_set, NULL) < 0)
		printf("sigprocmask SIG_BLOCK error\n");

	pr_mask(name);

	sigemptyset(&del_set);
	sigaddset(&del_set, SIGINT);

	if (sigprocmask(SIG_UNBLOCK, &del_set, &new_set) < 0)
		printf("sigprocmask SIG_UNBLOCK error\n");

	pr_mask(name);

	sigemptyset(&new_set);
	sigaddset(&new_set, SIGUSR1);

	if (sigprocmask(SIG_SETMASK, &new_set, NULL) < 0)
		printf("sigprocmask SIG_SETMASK error\n");
	
	pr_mask(name);

	return 0;
}
