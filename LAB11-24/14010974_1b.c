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
 	char f[2][3]={"f1", "f2"};
 	int i, in, fd[2];
 	
 	// “f1”과 “f2” open
		
	fd[0]=open(f[0], O_RDONLY);
	fd[1]=open(f[1], O_WRONLY);	

 	for (;;){
 		// “f1”에서 정수 읽기
 		read(fd[0],&in,sizeof(int));

 		printf("%d\n",in);
 		if (in==-1)
 			exit(0);
 		in = in+8;
		
		write(fd[1],&in,sizeof(int));
 		// “f2”로 정수 보내기
 	}

 	return 0;
}

