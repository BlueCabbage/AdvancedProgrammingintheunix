/*************************************************************************
    > File Name: pr_exit.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 10 Sep 2016 07:27:29 AM PDT
 ************************************************************************/
#include "apue.h"
#include <sys/wait.h>


void pr_exit(int status) 
{
	if (WIFEXITED(status)) {
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status)) {
		printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
				WCOREDUMP(status) ? " (core file generated)":"");
#else
		"");
#endif
	}
	else if (WIFSTOPPED(status)) {
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
	}
}
