#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  int i = 1;
  while(i < 4)
    printf("%s\n", argv[i++]);
}
