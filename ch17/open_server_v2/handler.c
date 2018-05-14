#include "opend.h"
#include <fcntl.h>

void handler_request(char *buf, int nread, int clifd, uid_t uid)
{
	int newfd;

	if (buf[nread-1] != 0) {
		snprintf(errmsg, MAXLINE - 1,
				"request from uid %d not null terminated: %*.*s\n",
				uid, nread, nread, buf);
		send_err(clifd, -1, errmsg);
		return;
	}
	log_msg("request: %s, from uid %d", buf, uid);
	/* parse the arguments, set options */
	if (buf_args(buf, cli_args) < 0) {
		send_err(clifd, -1, errmsg);
		log_msg(errmsg);
		return;
	}

	/* send the descriptor */
	if (send_fd(clifd, newfd) < 0)
		log_sys("send_fd error");
	log_msg("send fd %d over fd %d for %s", newfd, clifd, pathname);
	close(newfd); /* we're done with desciptor */
}

#define MAXARGC 50
#define WHITE  " \t\n"

int buf_args(char *buf, int (*optfunc)(int, char **)){
	char *ptr, *argv[MAXARGC];
	int argc;

	if (strtok(buf, WHITE) == NULL)
		return -1;
	argv[argc = 0] = buf;
	while ((ptr = strtok(NULL, WHITE)) != NULL) {
		if (++argc >= MAXARGC - 1) /* -1 for room FOR NULL at end */
			return -1;
		argv[argc] = ptr;
	}
	argv[++argc] = NULL;
	return ((*optfunc)(argc, argv));
}


int cli_args(int argc, char **argv){
	if (argc != 3 || strcmp(argv[0], CL_OPEN) != 0) {
		strcpy(errmsg, "usage: <pathname> <oflag>\n");
		return -1;
	}
	pathname = argv[1];
	oflag = atoi(argv[2]);
	return 0;
}
