#ifndef GET_CMSG_LEN_H
#define GET_CMSG_LEN_H

#if !defined(CMSG_LEN)
#include <sys/socket.h>
#define CMSG_LEN(N)	(sizeof(struct cmsghdr)+(N))
#endif

#endif
