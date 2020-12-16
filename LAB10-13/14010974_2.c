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


void do_child(void){
  	   //  process id, group id, session id 출력
            printf("\n pid : %d         pgid: %d        session id: %d\n",(int)getpid(),(int)getpgid(0),(int)getsid(0));
            exit(0); // 이 부분의 코드는 변경 금지
}

int main(void){
 	
	int n;
	pid_t pid[3];	
	int i,status;

	for(i = 0; i<3; i++) 
	{
		pid[i] = fork();
        	if (pid[i] == 0 && i == 0)
		{
			// first child process
			execl("./task_a","task_a","1","hello",(char *)0);
			exit(0); 
		}
		else if(pid[i] == 0 && i == 1)
		{
			// second child process
			execl("./task_b","task_b","2",(char *)0);
			exit(0);
		} 
		else if(pid[i] == 0 && i == 2)
		{
			// third child process
                        execl("./task_c","task_c","3",(char *)0);
			exit(0);
		}
	}
	for(i=2; i>=0; i--){ 
		n = waitpid(pid[i],&status,0);
		if(WIFEXITED(status))
		{
			printf("\n ******* [ 종료 =  %d ] ***** \n",WEXITSTATUS(status));
		}
		// 세 child의 종료 상태를 종료 순서대로 확인 & 출력
        }
	exit(0);
	
	return 0;
}









