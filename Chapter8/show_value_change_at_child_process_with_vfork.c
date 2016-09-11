/*************************************************************************
    > File Name: show_value_change_at_child_process_with_vfork.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 10 Sep 2016 07:11:04 AM PDT
 ************************************************************************/
#include "apue.h"

int globvar = 6; /* external variable in initialized data */


int main()
{
	int var; /*automatic variable on the stack */
	pid_t pid;

	var = 88;
	printf("before vfork()\n"); /* we don't flush stdio */
	if ((pid = vfork()) < 0) {
		printf("vfork error.");
		exit(0);
	}
	else if (pid == 0) { /* child */
		globvar ++;		 /*	modify parent's variables */
		var ++; 
		_exit(0);
	}

	/* parent continues here */
	printf("pid = %ld, glob = %d, var = %d.\n", (long)getpid(), globvar, var);


	exit(0);
}
