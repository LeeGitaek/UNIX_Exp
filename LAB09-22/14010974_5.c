#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>

extern int errno;

int main(){

	struct stat buf;
	int n;
	char str1[20];
	char dat[255];

	scanf("%s",&str1);

	lstat(str1,&buf);
	printf("심볼릭 링크 : %s => 파일 크기 : %d ,접근 권한 : %d\n",str1,(int)buf.st_size,(int)buf.st_mode&0777);
	
	n = readlink(str1,dat,255);
	if(n == -1)
	{
		perror("readlink");
		exit(1);
	}
	
	dat[n] = '\0';
	printf("readlink => %s\n",dat);
	lstat(dat,&buf);
	printf("파일 이름 : %s => 파일 크기 : %d , 접근 권한 : %d\n",dat,(int)buf.st_size,(int)buf.st_mode&0777);
	return 0;


}
