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
#include <sys/ipc.h>
#include <sys/msg.h>


struct q_entry{
 	long mtype;
 	int data;
};


int main(int argc,char** argv){
 	
	int i, qid, in, id;
 	key_t key;
 	struct q_entry msg;
 	id=atoi(argv[1]);
 	key=ftok("key", 3);
 		
	// message queue open
	qid=msgget(key, IPC_CREAT|0600);	 	
	for (i=0; i<5; i++) {
		scanf("%d",&in);
 		// mtype 설정
 		msg.mtype = id;
 		// 데이터 복사
		msg.data = in;
 		// message 보내기
 		msgsnd(qid, &msg, sizeof(int), 0);
 		// message 받기
 		msgrcv(qid, &msg, sizeof(int), id+3,0);
 		printf("%d\n", msg.data);
 	}
 	
	return 0;
}

