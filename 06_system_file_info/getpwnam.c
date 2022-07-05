#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>


struct passwd *getpwnam(const char *name) {

	struct passwd *ptr;


	setpwent();

	while((ptr = getpwent()) != NULL)
		if (strcmp(name, ptr->pw_name) == 0)
			break;
	endpwent();

	return ptr;
}


int main(int argc, const char *argv[]) {

	if (argc != 2)
		return -1;


	struct passwd *pwd;

	pwd = getpwnam(argv[1]);

	if (pwd == NULL)
		printf("pwd ptr is null\n");

	else {
		printf("pw_name: %s, pw_passed: %s, pw_uid: %u,\
			pw_gid: %u, pw_gevcos: %s, pw_dir: %s,\
		       	pw_shell: %s\n", pwd->pw_name, pwd->pw_passwd,\
			pwd->pw_uid, pwd->pw_gid, pwd->pw_gecos, pwd->pw_dir, \
			pwd->pw_shell);
	}

	return 0;
}

