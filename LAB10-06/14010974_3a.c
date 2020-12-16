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

int main(int argc, char *argv[]){
	int i ; 
	for(i= 0; i<3; i++)
	{
		printf("입력 문자열 : %s\n",argv[1]);
	}
	
	return 0;
}























