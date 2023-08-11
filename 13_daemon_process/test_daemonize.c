#include <stdio.h>
#include <unistd.h>

extern void daemonize(const char *cmd);

int main(int argc, const char *argv[])
{
	pid_t ppid;	
	char *cmd = "Test daemon creation.";

	ppid = getpid();

	printf("parent pid = %d\n", (unsigned int) ppid);

	daemonize(cmd);

	return 0;
}

