#include "apue.h"

int globvar = 6;

int main()
{
	int var,i;
	pid_t pid;
	char buf[10];

	var = 88;
	printf("before vfork\n");
	if ((pid = vfork()) < 0) {
		err_sys("vfork error");
	} else if (pid == 0) {
		globvar++;
		var++;
		fclose(stdout);
		exit(0);
	}

	i = printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar,
			var);
	sprintf(buf,"%d\n", i);
	write(STDOUT_FILENO, buf, strlen(buf));
	exit(0);
}

/*
 * This assumes that the standard I/O stream stdout is closed when the child
 * calls exit, not the file descriptor STDOUT_FILENO.
 * Some versions of the standard I/O library close the file descriptor associated 
 * with standard output,which would cause the write to standard output to also fail.
 *
 * */
