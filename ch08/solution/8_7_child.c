#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd,val;

	sscanf(argv[1], "%d", &fd);
	if ((val = fcntl(fd, F_GETFD, 0)) < 0){
		perror("fcntl error");
		exit(-1);
	}

	if (val & FD_CLOEXEC)
		printf("close-on-exec is on\n");
	else
		printf("close-on-exec is off\n");

	return 0;
}
