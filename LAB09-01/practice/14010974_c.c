#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int fd,i;
	char ch = "Y";

	fd = open("test1",O_WRONLY);
	if(fd == -1)
	{
		perror("error:");
		exit(1);
	}
	for(i = 0; i<5; i++){
		write(fd,&ch,1);
	}
	close(fd);	
	
	return 0;
}
