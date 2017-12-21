#include "apue.h"

#define BSZ 48

/* Investigate memory stream write behavior*/
int main()
{
    FILE *fp;
    char buf[BSZ];

    memset(buf, 'a', BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    if ((fp = fmemopen(buf, BSZ, "w+")) == NULL)
        err_sys("fmemopen failed");
    printf("initial buffer contents: %s\n", buf);
    fprintf(fp, "hello, world");
    printf("before flush: %s\n", buf);
    fflush(fp);
    printf("after fflush : %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    memset(buf, 'b', BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    fprintf(fp, "hello, world");
    fseek(fp, 0, SEEK_SET);
    printf("after fseek: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    memset(buf, 'c', BSZ-2);
    buf[BSZ - 2] = '\0';
    buf[BSZ - 1] = 'X';
    fprintf(fp, "hello, world");
    fclose(fp);
    printf("after fclose: %s\n",buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    return 0;
}
/* this example shows the policy for flushing memory streams and appending null bytes.
 * A null byte is appended automatically whenever we write to a memory stream and advanced
 * the stream's notion of the size of the stream's contents.
 *
 *
 * two functions that can be used to create a memory stream : 1) open_memstream 2) open_wmemstream
 *
 * */
