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
// reader 프로그램
 
int main(void)
{
	
	int n[10];
	int i;
	int fd;
	char *addr;

	fd = open("temp",O_RDWR);
	addr = mmap(NULL,512,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
		

	for(i = 0; i<10; i++)
	{
		scanf("%d",addr+i);
	}

	exit(0);





}





