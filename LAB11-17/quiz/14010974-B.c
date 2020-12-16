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

void catchusr(int signo) {
}


int main(void){
	int i, fd, *addr;
	pid_t pid;
	static struct sigaction act;
	
	act.sa_handler = catchusr;

        sigaction(SIGUSR1,&act,NULL);
       	
	fd = open("data1",O_RDWR);
	addr = mmap(NULL,512,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	pid=getpid();
	addr = pid;
	printf("B의 pid=%d\n", pid);
	i=1;
	pause();
	while(1){ 
		printf("reads ... %d\n",addr);
		i++;
		pause();
	}
	printf("bye...\n");
	exit(0);
}




