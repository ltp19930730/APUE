#include <dirent.h> /*opendir */
#include <unistd.h> /*execl(), fcntl() */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	DIR *dir;
	int val, fd, fd_2;
	char buf[10];
	pid_t pid;

	dir = opendir("/");
	fd = dirfd(dir);
	fd_2 = open("/",O_DIRECTORY);

	if ((val = fcntl(fd, F_GETFD, 0)) < 0)
		perror("fcntl error");

	printf("[opendir] : ");
	if (val & FD_CLOEXEC)
		printf("close-on-exec is on\n");
	else
		printf("close-on-exec is off\n");
	/* close close-on-exec flag */
	//val &= ~FD_CLOEXEC;
	//if (fcntl(fd,F_SETFD,val) < 0)
	//	perror("fcntl error");
	
	if ((val = fcntl(fd_2, F_GETFD, 0)) < 0)
		perror("fcntl error");

	printf("[open] : ");
	if (val &FD_CLOEXEC)
		printf("close-on-exec is on\n");
	else
		printf("close-on-exec is off\n");



	sprintf(buf, "%d\n", fd);

	if ((pid = fork()) < 0)
		perror("fork error");
	else if (pid == 0)
	{
		execl("/home/tluo/playground/APUE/ch08/solution/8_7_child","8_7_child", buf, NULL);
		exit(0);
	}

	return 0;
}
