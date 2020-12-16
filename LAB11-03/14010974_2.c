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

 void catchint(int);


 int main(void){

	int i, j, num[10], sum=0;
	static struct sigaction act;
	
	act.sa_handler=catchint;
	sigaction(SIGINT, &act, NULL);
	for (i=0; i<5; i++){
		signal(SIGINT,SIG_IGN);
		scanf("%d", &num[i]);
		sum+=num[i];
		for (j=0; j<=i; j++){
			printf("... %d\n", num[j]);
			sleep(1);
		}
		printf("SUM=%d\n", sum);
	}	
	 exit(0);

}

void catchint(int signo)
{
	printf("DO NOT INTERRUPT .... \n");
}
