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

#define N 5
struct data1{
pid_t pid;
char buf1[512];
};
struct data2{
// 추가 변수 정의
	struct data1 buf2[N];
};



int main(void){
	
 
	
	return 0;

}
