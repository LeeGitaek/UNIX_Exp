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
#include <ftw.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct q_entry{
	 long mtype;
	 int data; 
}; 

void do_child(int qid){
 	int i, pid=getpid(), id; 
	struct q_entry msg;
 	// 자신의 출력 순서 전달 받음
 	id = msgrcv(qid,&msg,sizeof(int),0,0);
	printf("pid=%d, id=%d\n", pid, id);
        
	if (id>1){
		// 자신의 출력 순서까지 대기
		msgsnd(qid,&msg,sizeof(int),0);
 	}

 	for(i=0; i<5; i++){
 		sleep(1);
		printf("%ld\n", pid);
	}

 	if (id<5){
 		// 다음 순서의 child에게 공지
 		msgrcv(qid,&msg,sizeof(int),0,0);
 	}
 	exit(0);
 }

int main(void){
	
	int i, in, pid, qid;
 	key_t key;
 	struct q_entry msg;
 	key=ftok("key", 2);
 	// message queue 만들기
 	qid = msgget(key,0600|IPC_CREAT);

 	for (i=0; i<5; i++){
 		scanf("%d", &in);
 		// child들에게 출력 순서 공지를 위한 작업
 		msgsnd(qid,&msg,sizeof(int),0);
 	}
 	for (i=0; i<5; i++){
 		if (fork()==0){
 			do_child(qid); 
			// 이 부분의 코드는 수정하면 안 됩니다.
 		}
 	}
 	for(i=0; i<5; i++)
 		wait(0);
 
	exit(0);
	
 	return 0;
}

