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

/* A program - 코드 작성자 : 이기택 
 * 날짜  : 2020.11.08 */ 

void catchint(int);


 int main(void){
	
	int fd,n;
	
	pid_t pid = getpid();
	int procId = (int)getpid();

	int bproc;
	int num;

	static struct sigaction act;

	act.sa_handler=catchint;
	sigaction(SIGINT,&act,NULL);

	fd = open("data1",O_RDWR|O_CREAT,0600);
	
	//printf("process id : %d - %d \n",(int)pid,procId);
	write(fd,&procId,sizeof(procId));
	 
	// 정지 
	pause();
	// 시그널 받고 다시 파일 열기 
	//2
	//printf("signal received\n");
	
	lseek(fd,0,SEEK_SET);
	read(fd,&bproc,sizeof(int)*10);
	//3
	//printf("b process id: %d\n",bproc);
	do {
		scanf("%d",&num);
		if(num > 0)
		{
			lseek(fd,0,SEEK_SET);
			write(fd,&num,sizeof(num));
			printf("writes ..... %d\n\n",num);
			kill(bproc,SIGUSR1);
			pause();			
		}
		else 
		{
			kill(bproc,SIGUSR2);
			
		}
	} while ( num > 0 );
	printf("bye...\n");
		
	exit(0);
}

void catchint(int signo)
{
	//1
}
