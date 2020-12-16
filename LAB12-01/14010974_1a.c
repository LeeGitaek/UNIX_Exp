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
#include <sys/sem.h>

union semun{
 	int val;
 	struct semid_ds *buf;
 	ushort *array;
};


int main(void){
	

	ushort buf[2]= {1,2};
	/* semaphore의 초기값 */;
	 int i, j, pid, semid;
 	key_t key;
 	union semun arg;
 	struct sembuf p_buf;
	key=ftok("key", 5);

	semid= semget(key,2, 0600|IPC_CREAT|IPC_EXCL); 
	// semaphore 생성
	
	if (semid==-1){
 		// semaphore get
 		semid = semget(key,2,0600);	
	}
 	else{
 		// semaphore 값 초기화
 		arg.array = buf;
 		semctl(semid, 0, SETALL, arg);
 	}
	
	pid=getpid();
 	for (i=0; i<3; i++){
 		// 동기화를 위한 semaphore 연산
		p_buf.sem_num=0;
		p_buf.sem_op=-1;
		p_buf.sem_flg=0;
		semop(semid, &p_buf, 1);

		for (j=0; j<3; j++){
 			printf("%d ... %ld\n", i, pid);
 			sleep(1);
 		}
 		// 동기화를 위한 semaphore 연산
 	
		p_buf.sem_num=1;
		p_buf.sem_op=1;
		p_buf.sem_flg = 0;
		semop(semid, &p_buf, 1);
 	}
 	return 0;


}

