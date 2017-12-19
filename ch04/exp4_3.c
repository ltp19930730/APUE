#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main()
{
    umask(0);
    if (creat("foo",RWRWRW) < 0)
        err_sys("create error for foo");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("boo",RWRWRW) < 0)
        err_sys("create error for bar");
    exit(0);

}