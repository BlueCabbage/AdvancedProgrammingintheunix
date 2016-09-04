/*************************************************************************
    > File Name: set_file_status_descriptor.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 03 Sep 2016 02:56:02 AM PDT
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>

void set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
	int val;

	if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
		printf("fcntl F_GETFL error");
		exit(0);
	}

	val |= flags;	/* turn on flags */

	if (fcntl(fd, F_SETFL, val) < 0) {
		printf("fcntl F_SETFL error");
		exit(0);
	}
}

