/*************************************************************************
    > File Name: show_environ.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 10 Sep 2016 12:58:33 AM PDT
 ************************************************************************/
#include "apue.h"

extern char **environ;

int main(void)
{
	int i; 
	char **env_ptr = environ;

	for (i = 1; environ[i] != '\0'; i ++) {
			printf("%s.\n", environ[i]);
	}

	exit(0);
}
