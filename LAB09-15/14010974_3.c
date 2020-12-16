#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	
	int i,fd,k,k1,data1[10],data2[10];
	
	fd = open("data3",O_RDWR | O_CREAT,0600);

	for(i = 0; i<10; i++)
	{
		scanf("%d",&data1[i]);
	}
	lseek(fd,0,SEEK_SET);
	i = 0;
	while(i<10)
	{	
		if(i%2 == 0)
		{  
			//printf("짝수 = %d\n",i);	
			k = lseek(fd,0,SEEK_CUR);
			//printf("짝수 k = %d\n",k);
			write(fd,&data1[i],sizeof(int));
		}
		else 
		{
			//printf("홀수 = %d\n",i);
			k1 = lseek(fd,0,SEEK_CUR);
			//printf("홀수 k = %d\n",k1);
			write(fd,&data1[i],sizeof(int));
		}
		i += 1;   
	}	
	//data1 배열의 0-4번째 정수를 data3 파일의 0 2 4 6 8 번째 위치에 저장 
	//data1 배열의 5-9번째 정수를 data3 파일의 1,3,5,7,9 번째 위치에 저장 
	
	
	lseek(fd,0,SEEK_SET);
	read(fd,&data2,10*sizeof(int)); 
	// data3 파일에 저장된 정수 10개를 읽어 data2 배열에 저장 
	//
	//
	
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
