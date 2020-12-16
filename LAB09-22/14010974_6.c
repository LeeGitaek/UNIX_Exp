#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <dirent.h>
#include <string.h>

extern int errno;

void cd_m(char **res){
	// cd 명령 수행
	chdir(res[1]);
}

void ls_m(char **res){
	// ls 명령 수행
	
   	DIR *dp;
	struct dirent *dent;
	
	if((dp = opendir(".")) == NULL)
	{
		perror("open dir :");
		exit(1);
	}

	while((dent = readdir(dp))) 
	{
		printf("%s\n", dent ->d_name);
	}	
	closedir(dp);
}
int main(void){ // main 함수는 수정하지 말고, 사용 하세요.
	char name[100], in[50], *res[20]={0};
	int i;
	while (1){
		// current working directory 표시
		printf("현재 디렉토리 : %s\n",getcwd(name,100));
		gets(in);
		i=0;
		res[i]=strtok(in, " ");
		while (res[i])
		{
			i++;
			res[i]=strtok(NULL, " ");
		}
		if (!strcmp(res[0], "cd"))
		{
			cd_m(res);
		}
		else if (!strcmp(res[0], "ls"))
		{
			ls_m(res);
		}	
		else
			exit(0);
	}

	return 0;
}
