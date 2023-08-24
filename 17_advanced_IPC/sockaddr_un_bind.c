#include "apue.h"
#include <sys/socket.h>
#include <sys/un.h>
#include <stddef.h>

int main(void)
{
	int fd, size;
	struct sockaddr_un sun;

	sun.sun_family = AF_UNIX;
	strcpy(sun.sun_path, "foo.socket");
	if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
		err_sys("socket failed");
	size = offsetof(struct sockaddr_un, sun_path) + strlen(sun.sun_path);
	if (bind(fd, (struct sockaddr *)&sun, size) < 0)
		err_sys("bind failed");
	printf("UNIX domaon socket bound\n");
}



