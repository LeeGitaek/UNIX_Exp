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

int main(void){
 	char name[100], in[50], *res[20]={0};
 	int i, status;
	pid_t pid;
	 while (1){
		// current working directory 표시
		printf("현재 디렉토리 : %s\n",getcwd(name,100));
        	gets(in);
		if (in[0]=='\0')
			continue;
	
		i=0;
		res[i]=strtok(in, " ");
		while (res[i]){
			res[++i]=strtok(NULL, " ");
		}
		if (strcmp(res[0], "exit")==0){
			exit(0);
		}
		else
		{
		// 명령으로 실행파일 이름을 입력 받아 해당 파일을 실행시키고
		// 인자를 전달하는 코드 작성
		//
			//printf("%s %s %s",res[0],res[1],res[2]);
			for(i=0; i<; i++)
			{
				if(pid == 0)
				{
					if(i == 0){
                               			char *argv[] ={ res[0],res[1], NULL};
                                		execvp(res[0],argv);
                        		} else if(i==1) {
                                		char *argv[] ={ res[0],res[1], NULL};
                                		execvp(res[0],argv);
                       			} else {
                                		char *argv[] ={ res[0],res[1], NULL};
                                		execvp(res[0],argv);
				}	}
			}	
		}
	}
	return 0;
}









