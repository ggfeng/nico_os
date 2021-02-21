#include "kenobi_platform.h"
#include "stdlib.h"
#include "stdio.h"
static struct kenobi_file_api file_api = {0};

int kenobi_platform_init(struct kenobi_file_api *platform_api) 
{
	 file_api.file_hal_init = platform_api->file_hal_init;
   file_api.file_hal_write = platform_api->file_hal_write;
   file_api.file_hal_read = platform_api->file_hal_read; 
	 file_api.file_hal_close = platform_api->file_hal_close;
   return 0;	
}


int kenobi_open(int len,void **argv)
{
	  int fd;
        /*  for(fd =0;fd<len;fd++)
	{
		printf("%d %s\n",fd,(char *)argv[fd]);
	}*/
	  kenobi_platform_init(&test_file_lapi);
	  if(file_api.file_hal_init)
			 fd = file_api.file_hal_init(len,argv);
		return fd;
}

int kenobi_write(int fd,int len,void **argv)
{
	   int ret = 0;
        for(fd =0;fd<len;fd++)
	{
		printf("%d %s\n",fd,(char *)argv[fd]);
        }
	   if(file_api.file_hal_write)
			  ret = file_api.file_hal_write(fd,len,argv);
		 return ret;
}

int kenobi_read(int fd,int len,void **argv)
{
	   int ret = 0;
	   if(file_api.file_hal_read)
			   ret = file_api.file_hal_read(fd,len,argv);
		 return ret;
}

int kenobi_close(int fd)
{
		 int ret = 0;
	   if(file_api.file_hal_close)
			   ret = file_api.file_hal_close(fd);
		 return ret;
}
