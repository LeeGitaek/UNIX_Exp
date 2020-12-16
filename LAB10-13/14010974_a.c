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

int main(int argc, char **argv){
	int i=0;
	
	for(i = 0; i<5; i++)
	{	
		printf("%s\n",argv[2]);
		sleep(1);
	}

	exit(atoi(argv[1]));

	return 0;
}






