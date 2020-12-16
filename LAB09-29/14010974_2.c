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

	
       printf("pid : %d		pgid: %d 	session id: %d\n",(int)getpid(),(int)getpgid(0),(int)getsid(0));

	return 0;

}










