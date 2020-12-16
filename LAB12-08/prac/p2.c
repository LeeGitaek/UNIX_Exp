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




int main(void){

     int i, shmid1, *buf1;

     shmid1=shmget(0111, 10*sizeof(int), 0600|IPC_CREAT);

     buf1=(int *)shmat(shmid1, 0, 0);

     for (i=0; i<5; i++){
          printf("%d\n", *(buf1+i));
     }

     exit(0);

}

