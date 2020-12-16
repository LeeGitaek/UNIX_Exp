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
#include <sys/wait.h>

void catchint(int signo);


void do_child(int i, int *cid){
  // SIGUSR1 signal 처리가 가능 하도록 설정
  
   int j;
   int k = 0;
   static struct sigaction act;
   act.sa_handler= catchint;
   sigaction(SIGUSR1,&act,NULL);
   
  // 자신의 출력 순서가 될 때까지 대기  

     
     printf("Created %dth child process", i);
     printf(" with Process ID = %d\n", getpid());            

     
    if(i<4) 
    {
	pause();
    }

    // 출력 완료 후 다음 출력 순서의 child에게 출력 시작을 알림
    for(j=0; j<5; j++) 
    {
          printf("child %d ..\n",getpid());
	  sleep(1);
    }
   
    if(i>0)
	kill(cid[i-1],SIGUSR1);

     exit(0);
    
}
  
int main(void){

      int i, status;
      pid_t pid[5];

 
      for (i=0;i<5;i++)
      {
	 pid[i]=fork();
	 
	if (pid[i]==0) 
	 {
 		do_child(i,pid);						
	 }
      }	

      for(i=0; i<5; i++)
      {
           wait(&status);
      } 
	
      exit(0);
     

      return 0;

}


void catchint(int signo){
	return;
}
