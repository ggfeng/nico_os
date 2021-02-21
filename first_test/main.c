#include "stdio.h"
#include "stdlib.h"
#include "kenobi_platform.h"

int main(char args,char *argv[])
{
	int fd;
	          
	fd = kenobi_open(args,(void *)argv);
        printf("open:%d \n",fd);
	fd = kenobi_write(fd,args,(void *)argv);
	fd = kenobi_read(fd,args,(void *)argv);
	return 0;
}

