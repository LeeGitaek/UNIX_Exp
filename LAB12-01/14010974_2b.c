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
	
	int fd, i, semid, *addr;
	key_t key;
	union semun arg;
 	struct sembuf p_buf;
	key=ftok("key", 1);
	
	semid = semget(key,1,0600|IPC_CREAT|IPC_EXCL);
	
	if(semid == -1){
		semid = semget(key,1,0600);
	}
	else {
		arg.val = 0;
		semctl(semid,0,SETVAL,arg);
	}
	
	// semaphore 생성 및 초기화
	fd = open("data1",O_RDWR|O_CREAT,0600);
	// file open & memory mapping
	addr= mmap(NULL, 512, PROT_READ|PROT_WRITE,MAP_SHARED, fd, 0);
	
	ftruncate(fd, 10*sizeof(int));
	for (i=0; i<10; i++){
		
		
		// semaphore signal
		p_buf.sem_num=0;
		p_buf.sem_op=1;
		p_buf.sem_flg = 0;
		semop(semid, &p_buf, 1);
		printf("%d\n",*(addr+i));
	}
	semctl(semid,IPC_RMID,0);
	exit(0);


}

