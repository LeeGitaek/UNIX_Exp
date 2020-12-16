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
#include <signal.h>

void backupAlarm(int signo){

	printf("\n..... backup .....\n");
	alarm(10);
	// backup 
	signal(SIGALRM,backupAlarm);
}
void backup(char **res){

	static char f1[512], f2[512]="TEMP/";
	char buf[512];
	int fd1, fd2, n;
	if (res!=NULL){
		mkdir("TEMP", 0700);
		strcpy(f1, res[1]);
		strcat(f2, res[1]);
	}
	fd1=open(f1, O_RDONLY);
	if (fd1==-1) return;
	fd2=open(f2, O_CREAT|O_WRONLY|O_TRUNC, 0600);
	 while((n=read(fd1, buf, 512))>0){
 		write(fd2, buf, n);
	}
}

int main(void){
 	
	char name[100], in[50], *res[20]={0};
 	int i, status;
	pid_t pid;
	static struct sigaction act;
	act.sa_handler = backupAlarm;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGALRM,&act,NULL);
	
	
// signal 처리 관련 설정
  while (1){
	
	getcwd(name, 99);
	printf("%s> ", name);
	if (gets(in)==NULL || in[0]=='\0')
		continue;
	i=0;
	res[i]=strtok(in, " ");
	
	while (res[i]){
		res[++i]=strtok(NULL, " ");
	}
	if (strcmp(res[0], "exit")==0){
		exit(0);
	}
	else if (strcmp(res[0], "cd_m")==0){
		chdir(res[1]);
	}
	else if (strcmp(res[0], "backup")==0){
		backup(&res[1]);		
         	alarm(10);
	} else{
		if ((pid=fork())==0){
	       		execvp(res[0], res);
			exit(0);
       		} 
		else{
			waitpid(pid, &status, 0);
		}
	}
  }
  return 0;
}






