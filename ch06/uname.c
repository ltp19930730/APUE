/* a simple implementation of system call uname */

#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct utsname buf;
	int fb = 0;

	if ((fb = uname(&buf)) < 0){
		perror("uname error");
		exit(0);
	} else {
		printf("system name : %s\n", buf.sysname);
		printf("node name   : %s\n", buf.nodename);
		printf("release     : %s\n", buf.release);
		printf("version     : %s\n", buf.version);
		printf("machine     : %s\n", buf.machine);
	}

	exit(0);
}

