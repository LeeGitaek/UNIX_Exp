#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int fd,i;
	int data = 35;

	fd = open("test2",O_WRONLY | O_CREAT,0640);
	if(fd == -1)
	{
		perror("error:");
		exit(1);
	}
	for(i = 0; i<10; i++){
		write(fd,&data,sizeof(int));
	}
	close(fd);	
	
	return 0;
}
