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
 	
	char fa[5]="fifo", f[6][3]={"f1", "f2", "f3", "f4", "f5", "f6"};
 	int i, in, id, fda, fd[2];
	// (1) id를 결정하는 코드 추가... printf("id=%d\n", id+1);
	printf("id=%d\n",id+1);

	fd[1]=open(f[id], O_WRONLY);
	fd[0]=open(f[id+3], O_RDONLY);

	scanf("%d", &in);
     	while (in!=-1){
	      	write(fd[1], &in, sizeof(int));
		read(fd[0], &in, sizeof(int));
		printf("%d\n", in);
		scanf("%d", &in);
	}
	
	// (2) id 결정을 위해 필요한 코드 추가...
	//
	exit(0);
}

