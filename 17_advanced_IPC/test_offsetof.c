#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/un.h>

struct pack {
	unsigned char a;
	int c;
	char b[100];
};

int main()
{
	printf("sockaddr_un len: %lu\n", sizeof(struct sockaddr_un));
	printf("sockaddr_un.sun_path: %lu\n", offsetof(struct sockaddr_un, sun_path));
	printf("pack len: %lu\n", sizeof(struct pack));
	printf("pack.b: %lu\n", offsetof(struct pack, b));

	return 0;
}

