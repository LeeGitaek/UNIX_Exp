#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void){

     int i, pid;


     for (i=0; i<3; i++){

          pid=fork();

          if (pid==0)

               printf("child....\n");

     }


     return 0;

}
