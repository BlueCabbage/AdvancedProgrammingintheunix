/*************************************************************************
    > File Name: with_compete_child_and_parent_8-12.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 11 Sep 2016 12:15:30 AM PDT
 ************************************************************************/
#include "apue.h"


static void charatatime(char *);



int main(void)
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		printf("fork error.");
	}
	else if (pid == 0) {
		/* child */
		charatatime("output from child.\n");
	}
	else {
		/* parent */
		charatatime("output from parent.\n");
	}

	exit(0);
}


static void charatatime(char *str) 
{
	char *ptr;
	int  c;

	setbuf(stdout, NULL);	/* set unbuffered */
	for (ptr = str; (c = *ptr++) != 0; ) {
		putc(c, stdout);
	}
		
}
