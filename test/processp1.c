#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void){

     int fd;

     pid_t pid;

     char buf[10];


     fd=open("data", O_RDONLY);

     read(fd, buf, 5);

     printf("before fork: %ld\n", lseek(fd, (off_t)0, SEEK_CUR));


     switch (pid=fork()){

          case -1: perror("fork failed\n");

                       exit(1);

                       break;

          case 0: printf("child before read: %ld\n", lseek(fd, (off_t)0, SEEK_CUR));

                       read(fd, buf, 5);

                      printf("child after read: %ld\n", lseek(fd, (off_t)0, SEEK_CUR));

                       break;

          default: wait((int*) 0);

                      printf("parent after wait: %ld\n", lseek(fd, (off_t)0, SEEK_CUR));

     }


   
   
	return 0;
}
