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


int main(){
    int i, cid, status;
	
	d_t pid[3];
     sigemptyset(&act.sa_mask);

     sigaddset(&act.sa_mask, SIGINT);

     sigaddset(&act.sa_mask, SIGUSR1);


     act.sa_handler=catchint;

     sigaction(SIGINT, &act, NULL);

     sigaction(SIGUSR1, &act, NULL);


     pid=fork();

     if (pid==0){

          for (i=0; i<3; i++){

               printf("%d ", i);

               sleep(1);

          }

          exit(0);

     }

     sleep(2);

     kill(pid, SIGINT);

     sleep(2);

     kill(pid, SIGUSR1);

     wait(&status);

     exit(0);
	return 0;

}


void catchint(int signo){

     int i; 

     for (i=0; i<3; i++){

          printf("%d ", signo);

          sleep(1);

     }

}
