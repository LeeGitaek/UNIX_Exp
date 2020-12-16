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
int main(int argc,char **argv)
{
        int i;


     printf("%d \n", argc);

     i=0;

     while(argv[i]!=NULL) {

          printf("%s \n", argv[i]);

          i++;

     }


	
 
	return 0;
}







