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

extern int errno;
int main(void)
{
	pid_t pid;

    printf("parent ... %ld : %ld : %d\n", getpid(), getppid(), getpgrp());

     pid=fork();

     if (pid==0){

         printf("chile before ... %ld : %ld : %d\n", getpid(), getppid(), getpgrp());

          setpgid(getpid(), getpid());

          printf("chile after ... %ld : %ld : %d\n", getpid(), getppid(), getpgrp());

          printf("%d\n", setsid());

          return 0;

     }

     wait(0);	
 
	return 0;
}







