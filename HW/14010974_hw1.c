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


void cat_m(char **res)
{	
        // (a) - cat 명령어를 수행하는 함수이다.
       	// => [구현 완료]
       	char buf[512];
	int fd,n;
	
	fd =  open(res[1],O_RDONLY);
	n = read(fd,buf,512);
	while(n)
	{	
		write(1,buf,n);
		n=read(fd,buf,n);
	}
	return;
}


void cd_m(char **res)
{
	// (b) - cd 명령어를 수행하는 함수이다. (2점) 
	// => [구현 완료]
	int stat;
	stat = chdir(res[1]);
	
	if(stat == -1)
	{
		perror("cd move error:");
		return;
	}
}

void cp_m(char **res)
{
	// (c) - cp 명령어를 수행하는 함수이다.
	// => [구현 완료]
	char buf[512];
	int fd1, fd2, n;
	
	fd1 = open(res[1],O_RDONLY);
	fd2 = open(res[2],O_WRONLY | O_CREAT | O_TRUNC, 0600);
	
	if(fd1 != -1)
	{
		n = read(fd1,buf,512);
		while(n)
		{
			write(fd2,buf,n);
			n=read(fd1,buf,n);
		}
	} 
	else 
	{
		perror("fd error:");
	}
	return;
}


void mkdir_m(char **res)
{
	// (d) mkdir 명령어를 수행하는 함수이다. (2점)
	// => [구현 완료]
	int stat;
	stat = mkdir(res[1], 0700);
	
	if(stat == -1)
	{
		perror("mkdir error :");
		return;
	}
}

void ls_m(char **res)
{
	// (e) ls-l 명령어를 수행하는 함수이다. (10점) 
	//=>[ 구현 완료]
	DIR *dp;
	struct dirent *dent;
	struct stat buf;

	if((dp = opendir(".")) == NULL)
	{	
		perror("open dir :");
		exit(1);
	}
	
	while((dent = readdir(dp)))
	{	
		lstat(dent->d_name,&buf);
		if(S_ISREG(buf.st_mode))
		{
			printf("F	");
		} 
		else if(S_ISDIR(buf.st_mode))
		{
			printf("D	");
		}
		printf("0%o	",(unsigned int)buf.st_mode&0777);
		printf("%o	",(unsigned int)buf.st_nlink);
		printf("%d	%d	%d	",(int)buf.st_uid,(int)buf.st_gid,(int)buf.st_size);
		time(&buf.st_mtime);
		printf("%s	",ctime(&buf.st_mtime));
		printf("%s\n",dent->d_name);
	}

	closedir(dp);
}

int main(void)
{
	// variables
	char name[100], in[50], *res[20] = {0};
	int i;

	
	// execute 
	while(1) 
	{
		/* current working directory 표시 */
		printf("현재 디렉토리 : %s\n",getcwd(name,100));
		/* current working directory 표시  end */

		gets(in);
		i = 0;
		res[i] = strtok(in," ");
		
		while(res[i])
		{
			i++;
			res[i] = strtok(NULL," ");
		}
		if(!strcmp(res[0], "cat"))
		{ 
			// cat 함수 호출 
			cat_m(res);
		}
		else if(!strcmp(res[0], "cd"))
		{
			//cd 함수 호출 
			cd_m(res);
		}
		else if(!strcmp(res[0], "cp"))
		{
			//cp 함수 호출 
			cp_m(res);	
		}
		else if(!strcmp(res[0], "mkdir"))
		{
			//mkdir 함수 호출 
			mkdir_m(res);
		}
		else if(!strcmp(res[0], "ls"))
		{
			ls_m(res);
		}
		else 
		{
			exit(0);
		}
	}
	
 
	return 0;
}







