/*************************************************************************
    > File Name: sig_int.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Fri 02 Sep 2016 06:50:16 AM PDT
 ************************************************************************/
#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);	/* our signal-catching function */

int main(void)
{
	char buf[MAXLINE];	/* from apue.h */
	pid_t pid;
	int status;

	if (signal(SIGINT, sig_int) == SIG_ERR)
			printf("signal error~!");

	printf("%% "); /* print prompt (print requires %% to print %) */
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;

		if ((pid = fork()) < 0) 
			printf("fork error~!");
		else if (pid == 0) { /* child */
			execlp(buf, buf, (char *)0);
			printf("couldn't execute: %s", buf);
			exit(127);
		}

		/* parent */
		if ((pid = waitpid(pid, &status, 0)) < 0)
			printf("waitpid error");

		printf("%% ");
	}


	exit(0);
}

void sig_int(int signo)
{
	printf("interrupt\n%% ");
}
