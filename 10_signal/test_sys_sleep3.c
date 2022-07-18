#include <stdio.h>


extern unsigned int sys_sleep3(unsigned int);



int main(void) {

	printf("sleep 5s...\n");
	
	sys_sleep3(5);

	printf("wake up\n");

	return 0;
}
