#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
    int fd,size;
    char s [ ]="Linux Programmer!\n",buffer[80];
    fd=open("test.txt",O_WRONLY|O_CREAT);
    if(fd == -1)
      printf("open failed!\n");
    else
      printf("open success!\n");
    write(fd,s,sizeof(s));
    close(fd);
    fd=open("test.txt",O_RDONLY);
    size=read(fd,buffer,sizeof(buffer));
    close(fd);
    printf("%s",buffer);
}
