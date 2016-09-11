/*************************************************************************
    > File Name: printuids_8-25.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 11 Sep 2016 01:43:24 AM PDT
 ************************************************************************/
#include "apue.h"

int main(void)
{
	printf("real uid = %d, effective uid = %d.\n", getuid(), geteuid());
	exit(0);
}
