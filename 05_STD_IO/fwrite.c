#include "apue.h"

struct Person {
	unsigned short age;
	time_t birthday;	
	char name[32];
}person;


int main(void) {

	struct Person person;

	strcpy(person.name, "ryan");
	person.age = 24;
	person.birthday = 881593200LL;

	FILE *fp;
	
	if ((fp = fopen("./person.dat", "w+")) == NULL)
		err_sys("fopen error");
	
	if (fwrite(&person, sizeof(person), 1, fp) != 1)
		err_sys("fwrite error");

	if (fclose(fp) == EOF)
		err_sys("fclose error");

	exit(0);
}


