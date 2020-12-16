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
#include <sys/mman.h>

void do_child(int id, int p[3][2]){
 	int i, in, pid=getpid();
	 // 불필요한 pipe 닫기
 	while(1){
		 //pipe에서 정수 읽기
		if (in==-1)
 			exit(0);
 		else
			printf("%d %d\n", pid, in);
 	}
 }


int main(void){
 	int i, in, pid, p[3][2];
 	// pipe 3개 생성
 	if(pipe(p) == -1)
	{
		perror("pipe call");
		exit(1);	
	}

     	for (i=0; i<3; i++){
 		if (fork()==0){
 			do_child(i, p);
 		}
 	}
	// 불필요한 pipe 닫
	close(p[1]);
	//
	for(i=0; i<12; i++){
 		scanf("%d", &in);
 		//pipe에 in 쓰기
 		write(p[1], &in, sizeof(in));
 	}
 	
	in=-1;
	
	for(i=0;i<3;i++){
 		if(fork()==0){
			do_child(in,p);
		}
	}
 	for(i=0;i<3;i++)
 		wait(0);
	
	exit(0);
}





