#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void ABC(void){

     printf("ABC ...");

}


void DEF(void){

     printf("DEF ...");

}


void GHI(void){

     printf("GHI ...");

}


int main(void){


     atexit(ABC);

     atexit(DEF);

     atexit(GHI);


     exit(15);

}
