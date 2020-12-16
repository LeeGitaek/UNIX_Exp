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

/* B program - 코드 작성자 : 이기택 
 * 날짜 : 2020.11.08 */ 

void catchint(int);
void catchfin(int);

 int main(void){
	
	int fd,n;
	int rdnum;
	int Aproc;
	int status;
	pid_t pid = getpid();
	int Bproc = (int)getpid();

	
	static struct sigaction act;
	static struct sigaction fin;

	act.sa_handler = catchint;
	fin.sa_handler = catchfin;

	sigaction(SIGUSR1,&act,NULL);
	sigaction(SIGUSR2,&fin,NULL);

	fd = open("data1",O_RDWR);
	
	if(fd == -1)
	{
		perror("write error  ");
		exit(0);
	}
        else
	{
		lseek(fd,0,SEEK_SET);
		read(fd,&Aproc, sizeof(int)*10);
				
		//printf("A process id:  %d\n",(int)Aproc);
		lseek(fd,0,SEEK_SET);
		write(fd,&Bproc,sizeof(Bproc));
	}
	kill(Aproc,SIGINT);
	pause();
	//printf("pause ===");
	while(1)
	{	
		lseek(fd,0,SEEK_SET);
		read(fd,&rdnum,sizeof(int));
		printf("reads...  %d\n\n",rdnum);
		kill(Aproc,SIGINT);
		pause();
	}
	

}
void catchfin(int signo)
{
	// sigusr2 handler
	printf("bye...\n");
	exit(0);

}
void catchint(int signo)
{
// sigusr1	
}
