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


int main(void){
	int i, in, fd, *addr;
	pid_t pid;
	fd= open("data1",O_RDWR);
	addr= mmap(NULL,512,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	while(1){ 
		sleep(3);
	}
	
	pid= read(fd,pid,sizeof(addr));
	printf("B의 pid=%d\n", pid);
	i=1;
	scanf("%d", &in);
	
	while(in>0){	
		write(fd,in,sizeof(in));
		i++;
		printf("writes ..... %d\n", in);
		kill(pid,SIGUSR1);
		scanf("%d", &in);
	}
	kill(pid,SIGUSR1);
	printf("bye...\n");
	exit(0);
}



