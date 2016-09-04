/*************************************************************************
    > File Name: print_the_status_of_the_confirm_file.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 03 Sep 2016 02:42:59 AM PDT
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>


int main(int argc, char * argv[])
{
	int val;

	if (argc != 2) {
		printf("usage: a.out <descriptor#>");
		exit(0);
	}

	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
		printf("fcntl error for fd %d", atoi(argv[1]));
		exit(0);
	}

	switch (val & O_ACCMODE) {
		case O_RDONLY:
			printf("read only");
			break;
		case O_WRONLY:
			printf("write only");
			break;
		case O_RDWR:
			printf("read write");
			break;
		default:
			printf("unknown access mode");
	}

	if (val & O_APPEND) 
		printf(", append");

	if (val & O_NONBLOCK)
		printf(", noblock");

	if (val & O_SYNC)
		printf(", synchronous writes");


#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
	if (val & O_FSYNC)
		printf(", synchronous writes");
#endif

	putchar('\n');


	exit(0);
}


