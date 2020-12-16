#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	struct stat buf;
	stat("data3",&buf);

	printf("퍼미션  = %o\n",(unsigned int)buf.st_mode&0777);
	printf("파일 크기 = %d\n",(int)buf.st_size);
	printf("링크  = %d\n",(int)buf.st_nlink);
	return 0;


}
