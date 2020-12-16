#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>

extern int errno;

int main(){

	int per;
	
	if(access("data1",F_OK) == -1 && errno == ENOENT) 
	{
		printf("data1 : 파일이 존재하지 않음 ");	
	}	
	
	per = access("data1",R_OK | W_OK);
	
	if(per == 0) 
	{
		printf("파일 읽기 쓰기 모두 가능합니다.");
	}
	else if(per == -1 && errno == EACCES)
	{	
		printf("읽기 쓰기 불가합니다.");
	}

	return 0;


}
