#include "apue.h"
#include <termios.h>
#include <setjmp.h>
#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif


static sigjmp_buf jmpbuf;

static void
pr_winsize(int fd)
{
	struct winsize size;

	if (ioctl(fd, TIOCGWINSZ, (char *) &size) < 0)
		err_sys("TIOCGWINSZ error");
	printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
}

static void
sig_winch(int signo)
{
	printf("SIGWINCH received\n");
	pr_winsize(STDIN_FILENO);
	siglongjmp(jmpbuf, 1);
}

int
main(void)
{
	if (isatty(STDIN_FILENO) == 0)
		exit(1);
	if (signal(SIGWINCH, sig_winch) == SIG_ERR)
		err_sys("signal error");
	pr_winsize(STDIN_FILENO); /* print initial size */

	if (sigsetjmp(jmpbuf, 1) != 0){
		if (signal(SIGWINCH, sig_winch) == SIG_ERR)
			err_sys("signal error");
	}
	for ( ; ; )               /* and sleep forever */
		pause();
}
