#ifndef COND_T_MUTEX_H
#define COND_T_MUTEX_H

struct msg {
	
	struct msg *m_next;
	
	long int job_id;
};


void process_msg(void);
void enqueue_msg(struct msg *);

#endif
