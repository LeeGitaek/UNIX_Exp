#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

    char ch[100]={0};
     
    link("test1", "test2");

    link("test1", "A/B/C/test3");

    symlink("A/B/C/test3", "test4");

    readlink("test4", ch, 100);

    printf("%s\n", ch);

    printf("%d\n", link("test4", "test5"));
	return 0;
}
