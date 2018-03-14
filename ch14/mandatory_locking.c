#include "apue.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>


void set_fl(int fd, int flag)
{
	int val;

	if ((val = fcntl(fd, F_GETFL,0)) < 0)
		err_sys("get file flag error");

	val |= flag;

	if (fcntl(fd, F_SETFL, val) < 0)
		err_sys("set file flag error");

}
int main(int argc, char *argv[])
{
	int fd;
	pid_t pid;
	char buf[5];
	struct stat statbuf;

	if (argc != 2) {
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		exit(1);
	}

	if ((fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0)
		err_sys("open error");
	if (write(fd, "abcdef", 6) != 6)
		err_sys("write error");

	/* important part: turn on set-group-ID and turn off group-execute */
	if (fstat(fd, &statbuf) < 0)
		err_sys("fstat error");
	if (fchmod(fd, (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
		err_sys("fchmod error");
	TELL_WAIT();

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid > 0){
		if (write_lock(fd, 0, SEEK_SET, 0) < 0)
			err_sys("write_lock error");

		TELL_CHILD(pid);

		if (waitpid(pid, NULL, 0) < 0)
			err_sys("waitpid error");
	} else {
		WAIT_PARENT();

		set_fl(fd, O_NONBLOCK);

		if (read_lock(fd, 0, SEEK_SET, 0) != -1)
			err_sys("child: read_lock succeeded");
		printf("read_lock of alread_locked region returns %d\n", errno);

		if (lseek(fd, 0, SEEK_SET) == -1)
			err_sys("lseek error");
		if (read(fd, buf, 3) < 0)
			err_ret("read failed (mandatory locking works)");
		else
			printf("read OK (no mandatory locking), buf = %s\n",buf);
	}
	exit(0);
}


