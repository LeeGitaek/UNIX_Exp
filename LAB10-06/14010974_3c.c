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
 // process id, group id, session id 출력
 	printf("process id : %d\n",(int)getpid());
	exit(0); // 이 부분의 코드는 변경 금지
 }
 int main(int argc, char *argv[]){
 	int num, i;
	char buf[3];
 	pid_t pid;

 	// main 함수의 인자를 정수로 변
	for (i=0; i<3; i++){
		// child process 생성 
		pid = fork();
 		if (pid == 0){
			if(i == 0)
				execlp("../bin/test2","test2","abc",NULL);
        		else if(i==1) 
				execlp("../bin/test2","test2","def",NULL);
        		else 
				execlp("../bin/test2","test2","ghi",NULL);	
 			do_child();
          	}
        }
       
	for (i=0; i<num; i++){ // 이 부분의 코드는 변경 금지
          	wait(0);
        }
           return 0;
}























