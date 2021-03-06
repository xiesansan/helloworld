#include <stdio.h>
#include <string.h>
#include "api.h"

void print_help()
{
	puts("helloworld help:");
	puts("./helloworld -w \"something\"");
	puts("./helloworld -r");
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		print_help();
		return 0;
	}

	int rw_type = -1;
	if (strcmp(argv[1], "-r") == 0)
	{
		rw_type = 0;
	}
	else
	if (strcmp(argv[1], "-w") == 0)
        {
                rw_type = 1;
        }
	else
	{
		rw_type = -1;
	}

	switch (rw_type)
	{
		case 0:
			read_hello("./helloworld.txt");
			break;
		case 1:
			if (argc < 3)
			{
				printf("please input write content.\n");
				return -1;
			}
			write_hello(argv[2], strlen(argv[2]) + 1);
			break;
		default:
			printf("hello i am comming!\n");
			break;
			
	}

	return 0;

}
