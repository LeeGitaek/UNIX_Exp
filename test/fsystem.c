#include <stdio.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/types.h>

int main()
{
	int fd,n;

	char buf1[20];

	fd=open("data5", O_WRONLY | O_TRUNC);

	printf("fd = %d \n",fd);

	n=read(fd, buf1, 20);

	printf("%d\n", n);

	//n=write(fd, buf2, 5);

	n=read(fd, buf1, 20);

	printf("%d\n", n);

	n = read(fd,buf1,20);

	printf("%d\n",n);
	//n=write(fd, buf2, 5);

	return 0;

}
