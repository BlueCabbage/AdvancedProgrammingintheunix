/*************************************************************************
    > File Name: show_args.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 10 Sep 2016 12:54:44 AM PDT
 ************************************************************************/
#include "apue.h"

int main(int argc, char *argv[])
{
	int i;
	for (i = 1; i <= argc; i ++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	exit(0);
}

