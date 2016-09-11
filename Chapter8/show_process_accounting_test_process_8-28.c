/*************************************************************************
    > File Name: show_process_accounting_8-28.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 11 Sep 2016 01:55:51 AM PDT
 ************************************************************************/
#include "apue.h"

int main(void)
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		printf("fork error.");
	}
	else if( pid != 0 ) {
		/* parent */
		sleep(2);
		exit(2); /* terminate with exit status 2 */
	}

	if ((pid = fork()) < 0) {
		printf("fork1 error.");
	}
	else if (pid != 0 ) {
		/* first child */
		sleep(4);
		abort(); /* terminate with core dump */
	}

	if ((pid = fork()) < 0 ){
		/* second child */
		printf("fork2 error.");
	}
	else if (pid != 0) {
		execl("/bin/dd", "if=/etc/passed", "of=/dev/null", NULL); 
		exit(7);	/* shouldn't get here*/
	}

	if ((pid = fork()) < 0) {
		printf("fork3 error.");
	}
	else if (pid != 0) {
		/* third child */
		sleep(8);
		exit(0);	/* normal exit */
	}

	sleep(6);	/* forth child */
	kill(getpid(), SIGKILL); /* terminate w/signal, no core dump */


	exit(6); /* shouldn't get here */
} 
