#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void cat_m(char **res){
 char buf[512]; // buffer 크기는 512 bytes 입니다. 이 부분은 수정하지 마세요.
 int fd, n;
 // 코드작성
  fd = open(*res,O_RDONLY);
  while(n > 0)
  {
	n = read(fd,&buf,511);
	buf[n] = '\0'; 
	printf("%s",buf);		
   } 
 }
 void cp_m(char **res){
  char buf[512]; // buffer 크기는 512 bytes 입니다. 이 부분은 수정하지 마세요.
  int fd1, fd2, n;
   // 코드작성
 }
 int main(void){ // main 함수는 수정하지 말고, 사용 하세요.
    char in[50], *res[20]={0};
    int i;
     while (1){
     	 printf("> ");
         gets(in);
         i=0;
         res[i]=strtok(in, " ");
         
	 while (res[i]){
         	i++;
         	res[i]=strtok(NULL, " ");
         }

          if (!strcmp(res[0], "cat")){
          	cat_m(res);
          }
          else if (!strcmp(res[0], "cp")){
          	cp_m(res);
          }
          else
	  {	
               exit(0);
           }
      }
      return 0;
}
