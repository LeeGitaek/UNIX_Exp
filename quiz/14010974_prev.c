#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

struct stud{ // 구조체 내용 변경하지 말 것
int no, id;
char name[20];
double score;
};
void vi_m(char **res){
	struct stud buf;
	int fd;
	//파일 open, 파일 이름은 res[1]에 저장
	scanf("%d", &buf.no);
	fd = open(buf.name,O_RDWR | O_CREAT,0600);
	getchar();
	while(buf.no>0){
	  // 나머지 정보 입력, scanf 사용 가능
  	// 순번 위치에 입력 내용 저장
  		scanf("%d", &buf.no);
		if(buf.no == -1) 
		{
			exit(1);
		}
		getchar();
	 }
      // 파일에 저장된 전체 내용 출력하고 return, printf 사용 가능
       
 }
   int main(void){ // main 함수 변경하지 말 것
	   char in[50], *res[20]={0};
	     int i;
	     while (1){
		     printf("> ");
	             gets(in);
		     if (!strcmp(in, ""))
		        continue;
		        i=0;
		       res[i]=strtok(in, " ");
                      while (res[i]){
        		 i++;
         		res[i]=strtok(NULL, " ");
         	     }
          	    if (!strcmp(res[0], "vi")){
                         vi_m(res);
           	    }
                     else
                      exit(0);
              }
 	return 0;  
}
