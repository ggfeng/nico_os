#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
 int i;
 if(argc != 3)
   printf("you should use 3 argument\n");
 for(i = 0;i<argc;i++)
  {
    printf("argc:%d,argv:%s\n",argc,argv[i]);
  }
 return 1;

}
