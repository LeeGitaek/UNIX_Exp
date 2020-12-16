#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int i,fd,data1[10], data2[10];

	for(i = 0; i< 10; i++)
	{
		scanf("%d",&data1[i]);
	}
	// data1 파일에 저장한다. 
	
	fd = open("data1",O_RDWR | O_CREAT | O_EXCL,0600);
	
	if(fd == -1)
	{
 		perror("error : exist");	
		exit(1);
		
	} 
	else
	{
		write(fd,&data1,10*sizeof(int));	
	}
	//
	// data1 파일을 읽어서 data2 에 저장한다. 

	lseek(fd,0,SEEK_SET);
	read(fd,&data2,10*sizeof(int));
	
	for(i = 0; i<10; i++)
	{
		printf("%-5d",data1[i]);
	}
	
	printf("\n");

	for(i = 0; i<10; i++)
	{
		printf("%-5d",data2[i]);
	}

	printf("\n");

	return 0;
}
