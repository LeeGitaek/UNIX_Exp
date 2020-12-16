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
#include <ftw.h>

int main(void){

	char f[6][3] = {"f1","f2","f3","f4","f5","f6"};
	int i, in, fda, fd[2];
	struct timeval t;


	for(i = 0; i<6; i++)
	{
		mkfifo(f[i],0600);
	}

	fd[0] = open(f[0],O_WRONLY);
	fd[1] = open(f[1],O_RDONLY);
	
	// client => f[id] , f[id+3]
	
	printf("======> Server On ..! ");
	
	for(;;){
			
				
	

	}

	return 0;

}
