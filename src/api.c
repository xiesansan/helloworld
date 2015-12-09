#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "api.h"

int read_hello(char *filepath)
{
	char buf[256] = {0};

	if (filepath == NULL)
	{
		printf("filepath is null\n");
		return -1;
	}

	int fd = open(filepath, O_WRONLY, 0700);
	off_t offset = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	int ret = read(fd, buf, offset);
	printf("read result: %s\n", buf);
	close(fd);

	return ret;	
}

int write_hello(char *buf, size_t size)
{
	if (buf == NULL)
    {
         printf("buf is null\n");
         return -1;
    }

    int fd = open("helloworld.txt", O_WRONLY|O_CREAT, 0700);
    int ret = write(fd, buf, size);
	if (ret > 0)
	{
		printf("write success!\n");
	}
	else
	{
		printf("write fail!\n");
	}

	return ret;
}

