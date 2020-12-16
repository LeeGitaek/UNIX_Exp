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
	int fd;
	char buf[3];
 	pid_t pid;
 	// main 함수의 인자를 정수로 변환
	num = atoi(argv[2]);
	printf("파일 명: %s\n 프로세스 fork  개수 : %d\n",argv[1],num);
	for (i=0; i<num; i++){
		// child process 생성 
		pid = fork();
 		if (pid == 0){
			fd = open(argv[1],O_RDONLY);
        		read(fd,&buf,2);
        		printf("%s\n",buf);
 			do_child();
          	}
        }
       
	for (i=0; i<num; i++){ // 이 부분의 코드는 변경 금지
          	wait(0);
        }
           return 0;
}























