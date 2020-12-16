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
void catchint(int signo);


int main(void){

     static struct sigaction act;

     int i, status;

     pid_t pid;


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

     sleep(2);

     kill(pid, SIGINT);    
    
     wait(&status);
    
     exit(0);
    
 }
    
   
void catchint(int signo){
     

        int i;
     
        for (i=0; i<3; i++){
    
                printf("%d ", signo);
     
                 sleep(1);
   
       }
   
}





