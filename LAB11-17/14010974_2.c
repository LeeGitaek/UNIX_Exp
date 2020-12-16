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


void do_child(int id, int p[2][2]){
 	char buf='a';
 	int i, pid=getpid();
 	
 	//순서가 될 때까지 대기 
	if(id < 2) 
		read(p[id][0],&buf,1);

 	for(i=0; i<5; i++){
 		sleep(1);
 		printf("%ld\n", pid);
	}
    	// 다음 출력 순서의 child 에게 순서가 되었음을 알리기 
	if(id > 0)
		write(p[id-1][1],&buf,1);  	

	exit(0);
}
 
int main(void){
 	
	int i, in, pid, p[2][2];

 	for(i = 0; i<2; i++)
	{
		pipe(p[i]);
	}

 	for (i=0; i<3; i++){
		if (fork()==0)
		{
			do_child(i, p);	
		}
 	}

 	for(i=0;i<3;i++)
	{
		wait(0);
	}

	exit(0);
}
