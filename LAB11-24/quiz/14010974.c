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


void do_child(int p[5][2]){
 	char buf='a';
 	int i, pid=getpid(), id;
	// 자신의 출력 순서 전달 받음
	
	
	printf("pid=%d, id=%d\n", pid, id);
	
	// 자신의 출력 순서까지 대기
	if(id < 2)
                read(p[id][0],&buf,1);

	for(i=0; i<5; i++){
		sleep(1);
		printf("%ld\n", pid);
	}
 
	// 다음 순서의 child에게 공지
	 if(id > 0)
                write(p[id-1][1],&buf,1);

	exit(0);
}




int main(void){
 	int i, in, pid, p[5][2];
	


	 for(i=0; i<5; i++){
 		pipe(p[i]);
	 }
	 
	for (i=0; i<5; i++){
		scanf("%d", &in);
		// child들에게 출력 순서 공지를 위한 작업
		write(p[i][1],&in,1);
	
	}
	
	for (i=0; i<5; i++){
		if (fork()==0){
			do_child(p); // 이 부분의 코드는 수정하면 안 됩니다.
		}
	
	}

	for(i=0; i<5; i++)
		wait(0);
	
	exit(0);
}


