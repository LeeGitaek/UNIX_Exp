#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MBUFF 512

int main(){
	int fd,n,i,ret;
	char ans[1];
	char *k = "Y";
	char f1_name[50];
	char f2_name[50];
	char buf[512];
	
	scanf("%s %s",&f1_name,&f2_name);
	fd = open(f1_name,O_RDONLY);
	if(fd == -1)
	{
		perror("error:");
		exit(1);
	}
	 
		
	fd = open(f2_name,O_WRONLY | O_CREAT | O_EXCL,0644);
	if(fd == -1)
	{	
		// file 존재함 
		perror("Warning : ");
		printf("do you want to overwrite it? (Y/N)");
		scanf("%s",&ans[0]);
		ret = strcmp(ans,k);
		if(ret==0)
		{	
				
			fd = open(f1_name,O_RDONLY);
			while(n > 0)
			{	
				n = read(fd,&buf,MBUFF);
				buf[n] = '\0';
				printf("%s",buf);
				fd = open(f2_name,O_WRONLY | O_CREAT | O_TRUNC,0644);
    				write(fd,buf,strlen(buf));
			}
			printf("copy success !\n");
		} 
		else 
		{
				printf("N : exit\n");
				exit(1);
		}
	}
		
	
	printf("\n");	

	close(fd);

	return 0;

}
