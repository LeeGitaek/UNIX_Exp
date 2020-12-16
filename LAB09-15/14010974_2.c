#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	char ch = 'X';
	char ch2 = 'Y';
	char ch3 = 'Z';
	char ch4 = 'T';
	char ch5 = 'S';
	char ch6 = 'W';

	int fd, i;

	fd = open("data2",O_RDWR | O_CREAT | O_EXCL,0600);

	if(fd == -1)
	{		
		perror("error : ");
		exit(1);
	}
	else 
	{
		for(i = 0; i<10; i++)
		{
			write(fd,&ch,sizeof(char));
		}
	}

	lseek(fd,0,SEEK_SET);
	write(fd,&ch2,sizeof(char));
	lseek(fd,0,SEEK_END);
	write(fd,&ch2,sizeof(char));
	
	for(i = 1; i<9; i++) 
	{
		if(i%2 != 0)
		{
			lseek(fd,i,SEEK_SET);
			write(fd,&ch3,sizeof(char));
		}
	}
	lseek(fd,15,SEEK_SET);
	write(fd,&ch4,sizeof(char));
			
	lseek(fd,-2,SEEK_END);
	write(fd,&ch5,sizeof(char));

	lseek(fd,-2,SEEK_CUR);
	write(fd,&ch6,sizeof(char));
	
		
	
	return 0;
}
