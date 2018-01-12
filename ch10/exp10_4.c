/* incomplete implementation of sleep */
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void
sig_alrm(int signo)
{
	/*nothing to do, just return to wake up the pause*/
}

unsigned int
sleep1(unsigned int seconds)
{
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return(seconds);
	alarm(seconds);    /* start the timer */
	pause();           /* next caught signal wakes us up */
	return (alarm(0)); /* turn off timer, return unslept time */
}

int main(void)
{
	printf("begin to sleep\n");
	sleep1(5);
	printf("end to sleep\n");

	exit(0);
}
