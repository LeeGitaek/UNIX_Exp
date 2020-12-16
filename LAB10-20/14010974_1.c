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

void catchint(int signo);


void do_child(int i){
  // SIGUSR1 signal 처리가 가능 하도록 설정
  
   int j; 
   static struct sigaction act;
   act.sa_handler= catchint;
   sigaction(SIGUSR1,&act,NULL);

  
   printf("%d-th child is created...\n", i);
   pause();
     
    
    
    for(j = 0; j<3; j++)
     {
		printf("프로세스 : %d\n",getpid()); 
     }
 	 // signal을 받으면, process id 세 번 출력 하도록 설정
     exit(i);
    
}
  
int main(void){

     int i, cid, status;
 	
     pid_t pid[3];

 
     for (i=0;i<3;i++){
	
	 pid[i]=fork();
 	
	if (pid[i]==0) {
 		do_child(i);
						
	 }
     }

	// 1초씩 sleep()하면서, child들에게 SIGUSR1 signal 보내기
     //signal(SIGUSR1,&a,NULL);    	
     //sleep(1);
    for(i = 0; i<3; i++)
     {
	sleep(1);
	kill(pid[i],SIGUSR1);
    }	

      for (i=0;i<3;i++){
		cid=wait(&status);
		printf("child id=%d, exit status=%d\n", cid, WEXITSTATUS(status));
      }
      exit(0);
     

      return 0;

}


void catchint(int signo){
	printf("catchint");
}
