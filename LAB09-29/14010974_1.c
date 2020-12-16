#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

extern int errno;

int main(void)
{

	
	struct stat s;
	struct dirent *d1;
	DIR * dp;
	dp = opendir(".");
	chdir(".");
	
	if(dp == NULL)
	{
		printf("no working directory");
		return;
	}

	while((d1 = readdir(dp)) != NULL)
	{

	       
       		lstat(d1->d_name,&s);           	
                if(!strcmp(d1->d_name,".") || !strcmp(d1->d_name,".."))
                	continue;
		if(S_ISDIR(s.st_mode))
		{
			printf("서브 디렉토리 이름 :  %s , 크기 : %d \n",d1->d_name,(int)s.st_size);
		} 
		else if(S_IXUSR & s.st_mode || S_IXGRP & s.st_mode ||
 S_IXOTH & s.st_mode) 
		{
			printf("실행 파일 이름 : %s , 크기 : %d \n",d1->d_name,(int)s.st_size);
		}
		
        }
	closedir(dp);
	

	return 0;
}










