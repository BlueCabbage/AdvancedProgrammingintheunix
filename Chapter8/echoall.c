/*************************************************************************
    > File Name: echoal.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 11 Sep 2016 12:51:18 AM PDT
 ************************************************************************/
#include "apue.h"

int main(int argc, char *argv[]) 
{
	int i;
	char **ptr;
	extern char **environ;

	for (i = 0; i < argc; i ++) {
		/* echo all command-line args */
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	for (ptr = environ; ptr != 0; ptr ++) {
		printf("%s.\n", *ptr);
	}


	exit(0);
}
