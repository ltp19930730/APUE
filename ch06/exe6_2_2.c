#include "apue.h"
#include <pwd.h>

/* Print encrypted password under FreeBSD and Mac OSX */

int main()
{
	struct passwd *ptr;

	if ((ptr = getpwnam("tesla")) == NULL)
		err_sys("getpwnam error");
	printf("pw_passwd = %s\n", ptr->pw_passwd == NULL ||
			ptr->pw_passwd[0] == 0 ? "(null)" : ptr->pw_passwd);
	exit(0);
}
