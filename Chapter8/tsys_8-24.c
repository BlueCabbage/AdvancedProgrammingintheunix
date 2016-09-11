/*************************************************************************
    > File Name: tsys_8-24.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 11 Sep 2016 01:40:42 AM PDT
 ************************************************************************/
#include "apue.h"



extern void pr_exit(int status);

int main(int argc, char *argv[])
{
	int status;

	if (argc < 2) {
		printf("command-line argument required");
		exit(0);
	}

	if ((status = system(argv[1])) < 0) {
		printf("system() error.\n");
	}

	pr_exit(status);
	

	exit(0);
}
