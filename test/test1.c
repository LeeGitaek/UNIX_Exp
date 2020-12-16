#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

	int fd,p,n;
	char ch1[10]="0123456789", ch2;

     //	fd=open("data2", O_RDWR|O_CREAT, 0600);
     //	write(fd, ch1, 10);
   //  	p=lseek(fd, 0, SEEK_CUR);
///	printf("1. %d\n",p);
//
     //	p=lseek(fd, 0, SEEK_SET);
    // 	read(fd, ch1, 5);
  //   	p=lseek(fd, 0, SEEK_CUR);
//	printf("2. %d\n",p);
//
  //   	p=lseek(fd, +2, SEEK_CUR);
 //    	printf("7  seek cur ? = %d\n",p);
//	n = read(fd, &ch2, 1);
//	printf("read = %d , ck = %c\n",n,ch2);
//     	n = write(1, &ch2, 1);
//	printf("%d\n",n);	

	fd=open("data1", O_RDWR);
	p = lseek(fd, -1, SEEK_SET);
	printf("1. %d\n",p);
	p = lseek(fd, +1, SEEK_SET);
	printf("2. %d\n",p);
	p = lseek(fd, -1, SEEK_END);
	printf("3. %d\n",p);
	p = lseek(fd, 0, SEEK_END);
	printf("4. %d\n",p);
	p = lseek(fd, 0, SEEK_CUR);
	printf("5. %d\n",p);
	return 0;
}
