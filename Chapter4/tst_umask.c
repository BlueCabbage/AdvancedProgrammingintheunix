/*************************************************************************
    > File Name: tst_umask.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 04 Sep 2016 01:40:45 AM PDT
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)


int main(void)
{
	umask(0);

	if (creat("foo", RWRWRW) < 0)
		printf("creat error for foo");

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (creat("bar", RWRWRW) < 0)
		printf("creat error for bar");


	exit(0);
}

