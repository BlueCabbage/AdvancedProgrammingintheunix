/*************************************************************************
    > File Name: open_a_file_and_unlink_it_then_sleep_15sec.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 04 Sep 2016 02:10:56 AM PDT
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>

int main(void)
{
	if (open("tempfile", O_RDWR) < 0)
		printf("open error");

	if (unlink("tempfile") < 0)
		printf("unlink error");

	printf("file unlinked\n");

	sleep(15);
	
	printf("done.\n");


	exit(0);
}
