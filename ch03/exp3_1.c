/* Figure 3.1 tests its standard input to see whether it is capable of seeking.
 * #include <unistd.h>
 *
 * off_t lseek(int fd, off_t offset, int whence);
 *  return new offset if OK, -1 if error
 */


#include "apue.h"

int main(int argc, char *argv[])
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek \n");
    else
        printf("seek OK\n");
    exit(0);
}


