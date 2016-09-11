/*************************************************************************
    > File Name: run_a_interpreter_file_with_exec_8-20.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 11 Sep 2016 01:11:02 AM PDT
 ************************************************************************/
#include "apue.h"
#include <sys/wait.h>

int main()
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		printf("fork error.\n");
	}
	else if (pid == 0) {
		/* child */
		if (execl("/home/zhaochao/Desktop/AdvancedProgrammingintheUNIX/Chapter8/testinterp", "testinterp", "myarg1", "ARG2", (char *)0) < 0) {
			printf("execl error.\n");
		}
	}

	if (waitpid(pid, NULL, 0) < 0) {
		/* parent */
		printf("waitpid error.\n");
	}


	exit(0);
}
