#include "apue.h"

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(){
    int var;
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
        err_sys("write error");
    printf("before fork\n"); // the standard output is line buffered if it's connected to a terminal device.

    if((pid = fork()) < 0 ) {
        err_sys("fork error");
    }else if (pid == 0) {
        globvar++;
        var++;
    } else {
        sleep(2);
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    exit(0);
}

/*
 * gcc exp8_1.c -o test
 * ./test
 *
 * a write to stdout
 * before fork
 * .....................
 * ....................
 *
 * ./test > a
 * cat a
 * a write to stdout
 * before fork
 * .....................
 * before fork
 * ....................
 * since the printf is buffered , we don't flush stdout and this will copy to child process.
 *
 *
 * /
