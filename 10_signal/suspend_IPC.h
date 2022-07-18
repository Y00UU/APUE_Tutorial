#ifndef SUSPEND_IPC_H
#define SUSPEND_IPC_H

#include <unistd.h>

void TELL_WAIT(void);
void TELL_PARENT(pid_t);
void WAIT_CHILD(void);
void TELL_CHILD(pid_t);
void WAIT_PARENT(void);


#endif
