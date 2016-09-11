/*************************************************************************
    > File Name: test_system_function_8-23.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 11 Sep 2016 01:33:28 AM PDT
 ************************************************************************/
#include "apue.h"
#include <sys/wait.h>


extern void pr_exit(int status);

int main(void)
{
	int status;

	if ((status = system("date")) < 0) {
		printf("system error.\n");
	}

	pr_exit(status);

	if ((status = system("nosuchcommand")) < 0) {
		printf("system1 error.\n");
	}

	pr_exit(status);

	if ((status = system("who; exit 44")) < 0) {
		printf("system2 error.\n");
	}

	pr_exit(status);



	exit(0);
}
