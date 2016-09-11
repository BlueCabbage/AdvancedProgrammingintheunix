/*************************************************************************
    > File Name: execle_in_child_process_8-16.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 11 Sep 2016 12:38:28 AM PDT
 ************************************************************************/
#include "apue.h"
#include <sys/wait.h>

char *env_init[] = { "USER=unknown", "PATH=/tmp", NULL };


int main(void) 
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		printf("fork error.\n");
	}
	else if (pid == 0) {
		/* specify pathname, specify environment */
		if (execle("/home/zhaochao/Desktop/AdvancedProgrammingintheUNIX/Chapter8/echoall", "echoall1", "myarg1", "MY ARG2", (char *)0, env_init) < 0) {
			printf("execle error.\n");
		}
	}
	
	if (waitpid(pid, NULL, 0) < 0) {
		printf("wait error.\n");
	}

	if ((pid = fork()) < 0) {
		printf("fork error.\n");
	}
	else if (pid == 0) {
		/* specify filename, inherit environment */
		if (execlp("/home/zhaochao/Desktop/AdvancedProgrammingintheUNIX/Chapter8/echoall", "echoall2", "only 1 arg", (char *)0) < 0) {
			printf("execlp error.\n");
		}
	}


	exit(0);
}

