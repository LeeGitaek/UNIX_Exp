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

int main(void)
{
	
	int fd, i;
	int *addr;
	fd= open("temp",O_RDWR);
	addr=mmap(NULL,512,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	
	sleep(5);
	
	for (i=0; i<5; i++){
		printf("%d\n", *(addr+i));
	}
	
	sleep(5);
	
	for (i=5; i<10; i++){
		printf("%d\n", *(addr+i));
	}
	exit(0);









}





