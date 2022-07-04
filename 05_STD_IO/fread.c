#include "apue.h"


struct Person {
	unsigned short age;
	time_t birthday;	
	char name[32];
}person;



int main(void) {

	struct Person person;
	
	FILE *fp;
	
	if ((fp = fopen("./person.dat", "r")) == NULL)
		err_sys("fopen error");
	
	if (fread(&person, sizeof(person), 1, fp) != 1)
		err_sys("fread error");

	if (fclose(fp) == EOF)
		err_sys("fclose error");

	printf("person name:%s, age:%u, birthday:%ld\n",\
			person.name, person.age, person.birthday);

	exit(0);
}


