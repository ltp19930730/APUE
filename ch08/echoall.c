#include "apue.h"
#include <unistd.h>

int
main(int argc, char *argv[])
{
	int i;
	char **ptr;
	extern char **environ;

	/* echo all command-line args */
	for (i = 0; i < argc; ++i)
		printf("argv[%d] : %s\n", i ,argv[i]);

	/* echo all env string */
	for (i = 0, ptr = environ; *ptr != 0; ptr++){
		printf("env[%d] :%s\n", i++ ,*ptr);
	}

	exit(0);
}
