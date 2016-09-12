/*************************************************************************
    > File Name: tst_a_orphan_process_group_9-12.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Mon 12 Sep 2016 02:08:21 AM PDT
 ************************************************************************/
#include "apue.h"
#include <errno.h>



static void sig_hup(int signo) 
{
	printf("SIGHUP received, pid = %ld.\n", (long)getpid());
}


static void pr_ids(char *name)
{
	printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld.\n",
				name, (long)getpid(), (long)getppid(), (long)getpgrp(), (long)tcgetpgrp(STDIN_FILENO));

	fflush(stdout);
}


int main(void)
{
	char c;
	pid_t pid;

	pr_ids("parent");

	if ((pid = fork()) < 0 ) {
		printf("fork error.");
	}
	else if ( pid > 0) {
		/* parent */
		sleep(5); /* sleep to let child stop itself */
	}
	else {
		/* child */
		pr_ids("child");
		signal(SIGHUP, sig_hup); /* establish signal handler */
		kill(getpid(), SIGTSTP); /* stop ourself */
		pr_ids("child"); /* prints only if we're continueed */

		if (read(STDIN_FILENO, &c, 1) != 1) {
			printf("read error %d on controlling TTY.\n", errno);
		}
	}


	exit(0);
}


