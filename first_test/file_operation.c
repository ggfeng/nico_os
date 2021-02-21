#include "kenobi_platform.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
struct kenobi_file_config{
FILE *fp1;
FILE *fp2;
};
static struct kenobi_file_config kenobi_file_config_t = {0};
static void do_help()
{
	printf("+++++++++++++++\n");
	printf("help-----------\n");
	printf("+++++++++++++++\n");
}
static int file_init(int len,void **argv)
{
	if(len<4)
	{
		printf("you should 3 world\n");
		do_help();
		return 0;
	}
	FILE* fp = fopen((char *)argv[1],"r");
	if(fp == NULL)
	{
		printf("canot find %s \n",(char *)argv[1]);
	        do_help();  
		return 0;
	}
	FILE* fp_output = fopen((char *)argv[2],"w+");   //输出文件
	if(fp_output == NULL)
	{
		printf("cannot open %s\n",(char *)argv[2]);
		do_help();
		return 0;
	}
	kenobi_file_config_t.fp1 = fp;
	kenobi_file_config_t.fp2 = fp_output;
	return 1;
}

static int file_write(int fd,int len,void **argv)
{
	int line,length;
	char buff[100];
	char *p;
	int set_flag = 0;
	line = 0;
	if(fd == 0)
	{
		printf("please open file\n");
		return 0;
	}
	while(fgets(buff,sizeof(buff),kenobi_file_config_t.fp1)!=NULL)
	{
		line++;
		length = strlen(buff);
		buff[length-1] = '\n';
		p = strstr(buff,"MODULE SUMMARY");
		if(p)
		{
			set_flag = 1;
			printf("%s %d\n",buff,line);
			fwrite(buff,length-1,1,kenobi_file_config_t.fp2);
			continue;
		}
		if(set_flag == 1)
		{
			p = strstr(buff,(char *)argv[3]);// 查找的文件
			if(p)
			{
				fwrite(buff,length-1,1,kenobi_file_config_t.fp2);
				set_flag = 0;
				return 1;
			}
		}
	}
        printf("cannt find %s\n",(char *)argv[3]);
	return 0;
}

static int file_read(int fd,int len,void **argv)
{
	char buff[100];
	if(fd == 0)
	{
		printf("cannot write success\n");
		return 0;
	}
	fread(buff,sizeof(buff),1,kenobi_file_config_t.fp2);
	printf("%s",buff);
	return 1;
}

static int file_close(int fd)
{
	if(fd == 0)
	{
		printf("cannot read success\n");
		return 0;
	}
	fclose(kenobi_file_config_t.fp1);
	fclose(kenobi_file_config_t.fp2);
	return 1;
}

struct kenobi_file_api test_file_lapi = 
{
	 .file_hal_init = file_init,
	 .file_hal_write = file_write,
	 .file_hal_read = file_read,
	 .file_hal_close = file_close,
};
