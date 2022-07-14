#ifndef SIGNAL_SET_H
#define SIGNAL_SET_H

#include <stdint.h>

enum SIGNAL {
SIGHUP = 1, SIGINT, SIGQUIT, SIGILL, SIGTRAP,
SIGABRT, SIGBUS, SIGFPE, SIGKILL, SIGUSR1,
SIGSEGV, SIGUSR2, SIGPIPE, SIGALRM, SIGTERM,
SIGSTKFLT, SIGCHLD, SIGCONT, SIGSTOP, SIGTSTP,
SIGTTIN, SIGTTOU, SIGURG, SIGXCPU, SIGXFSZ,
SIGVTALRM, SIGPROF, SIGWINCH, SIGIO, SIGPWR, SIGSYS
} sig_e;

typedef uint64_t sigset_t;

#define NSIG	(0x20)

#define sigemptyset(ptr) (*(ptr) = 0)
#define sigfillset(ptr) (*(ptr) = ~(sigset_t)0, 0)
int sigaddset(sigset_t *, int);
int sigdelset(sigset_t *, int);
int sigismember(const sigset_t *, int);

#endif
