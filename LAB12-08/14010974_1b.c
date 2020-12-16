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
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>


union semun{
 	int val;
 	struct semid_ds *buf;
 	ushort *array;
};

int main(void){
	
	int shmid, semid, i, n, *buf;
 	key_t key1, key2;
 	union semun arg;
 	struct sembuf p_buf;
 	key1=ftok("key", 1);
	// semaphore 생성 및 초기화
	semid = semget(key1,1,0600|IPC_CREAT|IPC_EXCL);
	
	if(semid == -1){
		semid = semget(key1,1,0);
	}
	else {
		arg.val = 0;
		semctl(semid,0,SETVAL,arg);
	}
	key2=ftok("key", 2);
	// 공유메모리 생성 및 초기화
	shmid = shmget(key2,10*sizeof(int),0600|IPC_CREAT);
	buf = (int *)shmat(shmid,0,0);
	
	for (i=0; i<10; i++){
		// semaphore wait
		p_buf.sem_num = 0;
		p_buf.sem_op = -1;
		p_buf.sem_flg = 0;
		semop(semid,&p_buf,1);
		// 공유메모리 내용 출력
		printf("%d\n",*(buf+i));
	}
	shmctl(shmid, IPC_RMID, 0);
	exit(0);
}
