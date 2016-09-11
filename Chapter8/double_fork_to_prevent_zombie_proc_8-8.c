/*************************************************************************
    > File Name: double_fork_to_prevent_zombie_proc_8-8.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 10 Sep 2016 07:56:18 AM PDT
 ************************************************************************/
#include "apue.h"
#include <sys/wait.h>

int main(void)
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		printf("fork error.");
		exit(0);
	}
	else if (pid == 0 ) { /* first fork */
		if ((pid = fork()) < 0) {
			printf("fork error.");
		}
		else if (pid > 0) {
			exit(0); /* parent from second fork == first child */
		}

	/*
	 *  We're the second child; our parent becomes init as soon
	 *  as our real parent calls exit() in the statement baove.
	 *  Here's where we'd coninue executing, knowing that when 
	 *  we're done, init will reap our status.
	 */

		sleep(2);
		printf("second child, parent pid = %ld\n", (long)getpid());
		exit(0);
	}


	if (waitpid(pid, NULL, 0) != pid) { /* wait for first child */
		printf("waitpid error.");
	}

	/*
	 *  We're the parent (the original process); we continue executing,
	 *  knowing that we're not the parent of the second child.
	 */
	exit(0);
}

