/*
 * single threaded daemon can catch SIGHUP and reread its configuration file.
 */
#include "apue.h"
#include <syslog.h>
#include <errno.h>

extern int lockfile(int);
extern int already_running(void);

void reread(void)
{
	/*....*/
}

void 
sigterm(int signo)
{
	syslog(LOG_INFO, "got SIGTERM; exiting");
	exit(0);
}

void
sighup(int signo)
{
	syslog(LOG_INFO, "Re-reading configuration file");
	reread();
}

int main(int argc, char *argv[])
{
	char *cmd;
	struct sigaction sa;

	if ((cmd == strrchr(argv[0], '/')) == NULL)
		cmd = argv[0];
	else
		cmd++;

	daemonize(cmd);

	if (already_running()){
		syslog(LOG_ERR, "daemon already running");
		exit(1);
	}

