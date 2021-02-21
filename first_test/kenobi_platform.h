#ifndef KENOBI_PLATFORM_H_
#define KENOBI_PLATFORM_H_

struct kenobi_file_api 
{
	 int (*file_hal_init)(int len,void **argv);
	 int (*file_hal_write)(int fd,int len,void **argv);
	 int (*file_hal_read)(int fd,int len,void **argv);
	 int (*file_hal_close)(int fd);
};

int kenobi_platform_init(struct kenobi_file_api *platform_api);
int kenobi_open(int len,void **argv);
int kenobi_write(int fd,int len,void **argv);
int kenobi_read(int fd,int len,void **argv);
extern struct kenobi_file_api  test_file_lapi;
#endif