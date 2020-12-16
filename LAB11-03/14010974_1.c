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

 void catchalarm(int);


 int main(void){
	
 	int i,num,sum = 0;   
	static struct sigaction act;
	
	act.sa_handler = catchalarm;
	
	
	for(i = 0; i< 10; i++)
	{
		signal(SIGALRM,catchalarm);
		alarm(10);
		if(scanf("%d",&num) != -1){
			alarm(0);
		}
		sum += num;
		printf("sum = %d\n",sum);

	}

	exit(0);
 }


void catchalarm(int signo)
{

	printf("input !! input !! input !! \n");
}
