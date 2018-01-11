#include <stdio.h>
#include <signal.h>
#include <error.h>
#include <unistd.h>

// defined in apue.h cannot include apue.h
static void sig_usr(int); /* one handler for both signal */

int main()
{
    if (signal(SIGUSR1,sig_usr) == SIG_ERR)
        perror("can't catch SIGUSR1");
    if (signal(SIGUSR2,sig_usr) == SIG_ERR)
        perror("can't catch SIGUSR2");
    for ( ; ; )
        pause();
}


static void
sig_usr(int signo)
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (signo == SIGUSR2)
        printf("received SIGUSR2\n");
    else
        perror("recevied signal error");
}

