/*************************************************************************
    > File Name: tst_chmod.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 04 Sep 2016 01:50:11 AM PDT
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>

int main(void)
{
	struct stat statbuf;

	/* turn on set-grout-ID and turn off group-execute */

	if (stat("foo", &statbuf) < 0)
		printf("stat error for foo");

	if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
		printf("chmod error for foo");

	/* set absolute mode to "rw-r--r--" */

	if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
		printf("chmod error for bar");


	exit(0);
}
