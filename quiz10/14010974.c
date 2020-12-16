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


void rm_m(char **res)
{
  char buf[501];
  int cnt;
  struct stat s;
  struct dirent *d1, *d2;
  DIR *dp1, *dp2;
  dp1 = opendir(res[1]);
  chdir(res[1]); // 두 문장 변경하지 말 것
  
    // 코드 작성 

   if(dp1 == NULL)
   {
	printf("no working directory");
	return;
   }
   while((d1 = readdir(dp1)) != NULL)
   {
	int ret = -1;
  	printf("%s / %s",res[1],d1->d_name);
	if(!strcmp(d1->d_name,".") || !strcmp(d1->d_name,".."))
		continue;
	if(!stat(buf,&s))
	{
		if(S_ISDIR(s.st_mode))
		{
			printf("IS directory : %s\n",buf);
			cnt+=1;
		} 
		else 
		{
			printf("is file : %s\n",buf);	
			ret = rmdir(buf);
			if(ret != -1)
			{
				printf("remove file : %s\n",buf);
			}
		} 
  	        printf("%s has %d files or directories",buf,cnt);
	}
   }
  chdir("..");   // 세 문장 변경하지 말 것
  
  if (rmdir(res[1]) == -1) 
  {
       printf("cannot remove %s\n", res[1]);
       printf("errno : %d",errno); 
  } 
  else 
  {
       printf("remove %s",res[1]);    	
  }
}

int main(void)
{ // main 함수 변경하지 말 것
  char name[100], in[50], *res[20] = {0};
  int i;
  while (1)
  {
    getcwd(name, 99);
    printf("%s> ", name);
    gets(in);
    i = 0;
    res[i] = strtok(in, " ");
    while (res[i])
    {
      i++;
      res[i] = strtok(NULL, " ");
    }
    if (!strcmp(res[0], "rm"))
    {
      rm_m(res);
    }
    else
      exit(0);
  }

  return 0;
}




