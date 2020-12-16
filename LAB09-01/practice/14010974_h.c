#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int fd,i;
	int n;
	int data[10]={0};

	fd = open("test2",O_RDONLY);
	if(fd == -1)
	{
		perror("error:");
		exit(1);
	}
	n = read(fd,&data,20);
	// 5*sizeof(int) => safe way 	
	for(i = 0; i<10; i++)
	{
		printf("%d",data[i]);
	}
	printf("\n");
	
	close(fd);	
	
	return 0;
}
