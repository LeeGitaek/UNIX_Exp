#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>

extern int errno;

int main(){
	
	char str1[20];
	char str2[20];

	scanf("%s",&str1);
	scanf("%s",&str2);

	link(str1,str2);
	
	
	
	return 0;


}
