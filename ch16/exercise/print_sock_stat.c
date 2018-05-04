#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void print_stat_info(struct stat buf){
	printf("ID of device containing file: %lld\n", (long long)buf.st_dev);
	printf("inode number: %lld\n",(long long)buf.st_ino);
    /* socket st_mode is 0140000 */
	printf("protection: 0%o\n", (unsigned int) buf.st_mode);
	printf("number of hard links: %lld\n",(long long)buf.st_nlink);
	printf("user ID of owner: %lld\n",(long long)buf.st_uid);
	printf("group ID of owner: %lld\n",(long long)buf.st_rdev);
	printf("total size, in bytes: %lld\n",(long long)buf.st_size);
	printf("blocksize of filesystem I/O: %lld\n", (long long)buf.st_blksize);
	printf("number of 512B blocks allocated %lld\n", (long long)buf.st_blocks);
}

int main(int argc, char *argv[]) 
{
	int sd;
	struct stat statbuf;

	if ((sd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0){
		perror("socket error");
		return -1;
	}
	if (fstat(sd, &statbuf) < 0) {
		perror("fstat error");
		return -1;
	}

	print_stat_info(statbuf);
}
