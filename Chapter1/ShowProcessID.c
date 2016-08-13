/*************************************************************************
    > File Name: ShowProcessID.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 13 Aug 2016 05:07:14 AM PDT
 ************************************************************************/

#include "apue.h"

int 
main(void) 
{
	printf("hello world form process ID: %ld\n", (long)getpid());
	
	exit(0);
}
