/*************************************************************************
    > File Name: showUIDGID.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Fri 02 Sep 2016 06:44:49 AM PDT
 ************************************************************************/
#include "apue.h"

int main(void)
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());
	
	exit(0);
}
