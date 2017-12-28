#include "apue.h"
#include <sys/wait.h>

int main()
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	}else if (pid == 0) {  /* first child */
		if ((pid = fork()) < 0)
			err_sys("fork error");
		else if (pid > 0)
			exit(0);
		/*
		 * We're the second child; our parent becomes init as
		 * soon as our real parent calls exit() in the statement above.
		 *
		 */
		sleep(4);
		printf("second child, parent pid = %ld\n",(long)getppid());
		exit(0);
	}

	if (waitpid(pid, NULL, 0) != pid)
		err_sys("waitpid error");

	exit(0);
}
