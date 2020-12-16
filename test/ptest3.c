#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	
char ch[100]={0};


    mkdir("T1", 0700);

    mkdir("T1/T2", 0700);

    mkdir("T1/T2/T3", 0700);

    symlink("T1/T2/T3", "T4");


    chdir("T4");

    getcwd(ch, 99);

    printf("%s\n", ch);


    chdir("..");

    getcwd(ch, 99);

    printf("%s\n", ch);


   
return 0;
}
