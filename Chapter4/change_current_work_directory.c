/*************************************************************************
    > File Name: change_current_work_directory.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Tue 06 Sep 2016 07:10:24 AM PDT
 ************************************************************************/
#include "apue.h"

int main(void)
{
	if (chdir("/tmp") < 0) {
		printf("chdir failed.");
		exit(0);
	}
	
	printf("chdir to /tmp successed.\n");

	
	exit(0);
}
