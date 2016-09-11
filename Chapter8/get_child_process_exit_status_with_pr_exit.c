/*************************************************************************
    > File Name: get_child_process_exit_status.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 10 Sep 2016 07:33:18 AM PDT
 ************************************************************************/
#include "apue.h"
#include <sys/wait.h>


extern void pr_exit(int status);

int main(void)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) < 0) {
		printf("fork error.");
		exit(0);
	}
	else if (pid == 0) {  /* child */
		exit(7);
	}

	if (wait(&status) != pid) { /* wait for child */
		printf("wait error.\n");
	}
	
	pr_exit(status); 	  /* and print its status */



	if ((pid = fork()) < 0) {
		printf("fork2 error.");
		exit(0);
	}
	else if (pid == 0) { /* child */
		abort();		 /* generates SIGABRT */
	}

	if (wait(&status) != pid) { /* wait for child */
		printf("wait error.");
	}

	pr_exit(status);			/* and print its status */



	if ((pid = fork()) < 0) { 
		printf("fork error.");
	}
	else if (pid == 0) {		/* child */
		status /= 0;			/* devide by 0 generates SIGFPE */
	}

	if (wait(&status) != pid) { /* wait for child */
		printf("wait error.");
	}

	pr_exit(status);			/* and print its status */



	exit(0);

}
