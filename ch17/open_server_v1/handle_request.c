#include "opend.h"
#include <fcntl.h>

void handle_request(char *buf, int nread, int fd)
{
	int newfd;

	if (buf[nread - 1] != 0) {
		snprintf(errmsg, MAXLINE -1,
				"request not null terminated: %*.*s\n", nread, nread, buf);
		send_err(fd, -1, errmsg);
		return;
	}
	if (buf_args(buf, cli_args) < 0) { /* parse args & set options */
		send_err(fd, -1, errmsg);
		return;
	}
	if ((newfd = open(pathname, oflag)) < 0) {
		snprintf(errmsg, MAXLINE-1,"can't open %s : %s\n", pathname, strerror(errno));
		send_err(fd, -1, errmsg);
		return;
	}
	if (send_fd(fd, newfd) < 0) /*send the descriptor */
		err_sys("send_fd error");
	close(newfd); /* we're done with descriptor */
}

#define MAXARGC 50 /* max number of arguements in buf  */
#define WHITE " \t\n" /* white space for tokenizing arguments */

int buf_args(char *buf, int (*optfunc)(int, char **)){
	char *ptr, *argv[MAXARGC];
	int argc;

	if (strtok(buf, WHITE) == NULL) /* an argv[0] is required */
		return -1;
	argv[argc = 0] = buf;
	while ((ptr = strtok(NULL, WHITE)) != NULL) {
		if (++argc >= MAXARGC-1)
			return -1;
		argv[argc] = ptr;
	}
	argv[++argc] = NULL;

	return (*optfunc)(argc, argv);
}

int cli_args(int argc, char **argv)
{
	if (argc != 3 || strcmp(argv[0], CL_OPEN) != 0) {
		strcpy(errmsg, "usage: <pathname> <oflag>\n");
		return -1;
	}
	pathname = argv[1]; 
	oflag = atoi(argv[2]);
	return 0;
}
