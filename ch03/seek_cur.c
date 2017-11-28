#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
    int fd;
    fd = open("/tmp/test",O_WRONLY | O_CREAT);
    char s[] = "Linux programming";
    write(fd,s,sizeof(s));
    off_t currpos;
    currpos = lseek(fd, 0, SEEK_CUR);
    printf("cur pos : %d",currpos);
    return 0;
}
    
