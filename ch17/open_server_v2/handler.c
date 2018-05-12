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
