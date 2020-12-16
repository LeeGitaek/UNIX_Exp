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

int main(int argc, char **argv){
	int i;
	int fd; 
	char buf[2];
	
	fd = open("./data",O_RDONLY);
	
	for(i = 0; i<10; i++)
	{
		read(fd,buf,1);
		write(1,buf,1);
		write(1,"\n",1);
		sleep(1);
	}
	exit(atoi(argv[1]));
	
	return 0;
}






